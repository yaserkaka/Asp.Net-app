#include "ToDoList.h"
using namespace std;
ToDoList::ToDoList() : frontPtr(NULL), rearPtr(NULL) {}

ToDoList::~ToDoList() {
    while (!isEmpty()) {
        Node* temp = frontPtr;
        frontPtr = frontPtr->next;
        delete temp;
    }
}

void ToDoList::addTask(string& desc) {
    Node* newNode = new Node(desc);
    if (isEmpty()) {
        frontPtr = rearPtr = newNode;
    } else {
        rearPtr->next = newNode;
        rearPtr = newNode;
    }
}

void ToDoList::markTaskAsCompleted(int index) {
    Node* current = frontPtr;
    int i = 0;
    while (current != NULL && i < index) {
        current = current->next;
        i++;
    }
    if (current != NULL) {
        current->completed = true;
        cout << "Task marked as completed: " << current->description << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

void ToDoList::displayTasks() const {
    if (isEmpty()) {
        cout << "No tasks in the to-do list." << endl;
    } else {
        std::cout << "To-Do List:" << std::endl;
        Node* current = frontPtr;
        int index = 1;
        while (current != nullptr) {
            cout << "[" << (current->completed ? "X" : " ") << "] " << index << ". " << current->description << endl;
            current = current->next;
            index++;
        }
    }
}

void ToDoList::saveToFile( string& filename)  {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        Node* current = frontPtr;
        while (current != NULL) {
            outFile << current->description << "," << (current->completed ? "1" : "0") << endl;
            current = current->next;
        }
        std::cout << "To-do list saved to " << filename << std::endl;
        outFile.close();
    } else {
        std::cout << "Error: Unable to open file for writing." << std::endl;
    }
}

void ToDoList::loadFromFile(string& filename) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        while (!isEmpty()) {
            Node* temp = frontPtr;
            frontPtr = frontPtr->next;
            delete temp;
        }

        string line;
        while (getline(inFile, line)) {
            size_t commaPos = line.find(',');
            if (commaPos != string::npos) {
                string desc = line.substr(0, commaPos);
                bool completed = (line.substr(commaPos + 1) == "1");
                addTask(desc);
                rearPtr->completed = completed;
            }
        }

       cout << "To-do list loaded from " << filename << endl;
        inFile.close();
    } else {
        cout << "Error: Unable to open file for reading. Creating a new to-do list." << endl;
    }
}

bool ToDoList::isEmpty() const {
    return frontPtr == NULL;
}

Node* ToDoList::front() const {
    return frontPtr;
}

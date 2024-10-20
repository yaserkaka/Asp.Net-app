#include "ToDoList.h"
using namespace std;
int main() {
     string fileName = "ToDoList.txt";
    ToDoList toDoList;

    // Load existing to-do list from file
    toDoList.loadFromFile(fileName);

    int choice;
    do {
        cout << "1. Add Task\n2. Mark Task as Completed\n3. Display Tasks\n4. Save to File\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string taskDescription;
                cout << "Enter task description: ";
                cin.ignore(); // Clear the input buffer
                getline(std::cin, taskDescription);
                toDoList.addTask(taskDescription);
                break;
            }
            case 2: {
                int taskIndex;
                cout << "Enter the index of the task to mark as completed: ";
                cin >> taskIndex;
                toDoList.markTaskAsCompleted(taskIndex - 1); // Adjust index for zero-based array
                break;
            }
            case 3:
                system("CLS"); // Clear the console screen
                toDoList.displayTasks();
                break;
            case 4:
                toDoList.saveToFile(fileName);
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

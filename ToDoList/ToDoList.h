#ifndef TODOLIST_H
#define TODOLIST_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Node {
    string description;
    bool completed;
    Node* next;

    Node( string& desc, bool comp = false)  {
        description=desc;
        completed=comp;
         next=NULL;
    }
};

class ToDoList {
private:
    Node* frontPtr;
    Node* rearPtr;

public:
    ToDoList();
    ~ToDoList();
    void addTask( string& desc);
    void markTaskAsCompleted(int index);
    void displayTasks() const;
    void saveToFile(string& filename) ;
    void loadFromFile( string& filename);
    bool isEmpty() const;
    Node* front() const;
};

#endif // TODOLIST_H

// mohey -> task manger
#include <iostream>
using namespace std;

struct Task {
    string description;
    Task* next;

    Task( string taskDescription) {
        description = taskDescription;
        next = nullptr;
    }
};

class TaskManager {

public:
    Task* head;
    Task* tail;
    int taskCount;

    TaskManager() {
        head = nullptr;
        tail = nullptr;
        taskCount = 0;
    }

    void addToHead(string description) {
        Task* newTask = new Task(description);
        if (isEmpty()) {
            head = tail = newTask;
        } else {
            newTask->next = head;
            head = newTask;
        }
        taskCount++;
    }

    void addToTail(string description) {
        Task* newTask = new Task(description);
        if (isEmpty()) {
            head = tail = newTask;
        } else {
            tail->next = newTask;
            tail = newTask;
        }
        taskCount++;
    }

    void display() {
        if (isEmpty()) {
            cout << "The task list is empty." << endl;
            return;
        }

        Task* current = head;
        while (current != nullptr) {
            cout<< "Description: " << current->description << endl;
            current = current->next;
        }
        
    }

    void deleteFromHead() {
        if (isEmpty()) {
            cout << "The task list is already empty." << endl;
            return;
        }

        Task* temp = head;
        head = head->next;
        delete temp;
        taskCount--;

        if (head == nullptr) {
            tail = nullptr; 
        }
    }

    void deleteFromTail() {
        if (isEmpty()) {
            cout << "The task list is already empty." << endl;
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Task* current = head;
            while (current->next != tail) {
                current = current->next;
            }

            delete tail;
            tail = current;
            tail->next = nullptr;
        }
        taskCount--;
    }

    int count() {
        return taskCount;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    Task* findInList(string name) {
        Task* current = head;
        while (current != nullptr) {
            if (current->description == name) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    ~TaskManager() {
        while (!isEmpty()) {
            deleteFromHead();
        }
    }
};

int main() {
    // TaskManager manager;

    // manager.addToHead("Finish homework");
    // manager.addToHead("Call mom");
    // manager.addToTail("Buy groceries");

    // manager.display();

    // Task* foundTask = manager.findInList("Call mom");
    // if (foundTask) {
    //     cout<<"Description: " << foundTask->description << endl;
    // } else {
    //     cout << "Task not found." << endl;
    // }

    // manager.deleteFromHead();
    // manager.display();

    // manager.deleteFromTail();
    // manager.display();

    // manager.count();

    return 0;
}

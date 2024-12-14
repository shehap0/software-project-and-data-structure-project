#include <iostream>
#include <string>
using namespace std;

struct Node {
    string url;
    Node* next;
    Node* prev;
};

class BrowserHistory {
public:
    BrowserHistory() {
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void addToHead(const string& url) {
        Node* newNode = new Node;
        newNode->url = url;
        newNode->next = head;
        newNode->prev = nullptr;

        if (isEmpty()) {
            head = tail = newNode;
        } else {
            head->prev = newNode;
            head = newNode;
        }
    }

    void addToTail(const string& url) {
        Node* newNode = new Node;
        newNode->url = url;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "The history is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->url << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void deleteFromHead() {
        if (isEmpty()) {
            cout << "The history is empty. Cannot delete from head." << endl;
            return;
        }

        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        cout << "Deleted from head." << endl;
    }

    void deleteFromTail() {
        if (isEmpty()) {
            cout << "The history is empty. Cannot delete from tail." << endl;
            return;
        }

        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        cout << "Deleted from tail." << endl;
    }

    void deleteSpecific(const string& url) {
        if (isEmpty()) {
            cout << "The history is empty. Cannot delete specific URL." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr && temp->url != url) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "URL not found in the history." << endl;
            return;
        }

        if (temp == head) {
            deleteFromHead();
        } else if (temp == tail) {
            deleteFromTail();
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            cout << "Deleted URL: " << url << endl;
        }
    }

    int count() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    bool findInList(const string& url) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->url == url) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

private:
    Node* head;
    Node* tail;
};

int main() {
    BrowserHistory history;

    history.addToHead("google.com");
    history.addToTail("github.com");
    history.addToTail("stackoverflow.com");

    cout << "Current History:" << endl;
    history.display();

    cout << "Deleting from head:" << endl;
    history.deleteFromHead();
    history.display();

    cout << "Deleting specific URL (github.com):" << endl;
    history.deleteSpecific("github.com");
    history.display();

    cout << "Deleting from tail:" << endl;
    history.deleteFromTail();
    history.display();

    cout << "Count of URLs in history: " << history.count() << endl;

    cout << "Finding URL (stackoverflow.com): " << (history.findInList("stackoverflow.com") ? "Found" : "Not Found") << endl;

    return 0;
}

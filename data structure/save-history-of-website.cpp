#include <iostream>                 // El Big

struct Node {
    std::string url;
    Node* next;
};

class BrowserHistory {
public:
    BrowserHistory() {
        head = nullptr;
    }

    void push(const std::string& url) {
        Node* newNode = new Node;
        newNode->url = url;
        newNode->next = head;
        head = newNode;
    }

    std::string pop() {
        if (head == nullptr) {
            return ""; // Handle empty history
        }
        Node* temp = head;
        std::string url = head->url;
        head = head->next;
        delete temp;
        return url;
    }

private:
    Node* head;
};
#include <iostream>
using namespace std;

// adham -> contact book
struct Contact {
    string name;
    string phone;
    Contact* next;
    Contact* prev;

    Contact(string n, string p) : name(n), phone(p), next(nullptr), prev(nullptr) {}
};

class ContactBook {
private:
    Contact* head;
    Contact* tail;
    int count;

public:
    ContactBook() : head(nullptr), tail(nullptr), count(0) {}

    ~ContactBook() {
        while (!isEmpty()) {
            deleteFromHead();
        }
    }

    void addToHead(string name, string phone) {
        Contact* newContact = new Contact(name, phone);
        if (isEmpty()) {
            head = tail = newContact;
        } else {
            newContact->next = head;
            head->prev = newContact;
            head = newContact;
        }
        count++;
    }

    void addToTail(string name, string phone) {
        Contact* newContact = new Contact(name, phone);
        if (isEmpty()) {
            head = tail = newContact;
        } else {
            tail->next = newContact;
            newContact->prev = tail;
            tail = newContact;
        }
        count++;
    }

    void display() {
        if (isEmpty()) {
            cout << "Contact book is empty." << endl;
            return;
        }
        Contact* current = head;
        while (current != nullptr) {
            cout << "Name: " << current->name << ", Phone: " << current->phone << endl;
            current = current->next;
        }
    }

    void deleteFromHead() {
        if (isEmpty()) {
            cout << "Contact book is empty." << endl;
            return;
        }

        Contact* temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }

        delete temp;
        count--;
    }

    void deleteFromTail() {
        if (isEmpty()) {
            cout << "Contact book is empty." << endl;
            return;
        }

        Contact* temp = tail;
        tail = tail->prev;

        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }

        delete temp;
        count--;
    }

    int countContacts() const {
        return count;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    Contact* findInList(string name) {
        Contact* current = head;
        while (current != nullptr) {
            if (current->name == name) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
};

int main() {
    ContactBook contactBook;

    contactBook.addToHead("John Doe", "123-456-7890");
    contactBook.addToTail("Jane Smith", "234-567-8901");
    contactBook.addToTail("Alice Brown", "345-678-9012");

    cout << "Contact Book:" << endl;
    contactBook.display();

    cout << "Total contacts: " << contactBook.countContacts() << endl;

    string searchName = "Jane Smith";
    Contact* foundContact = contactBook.findInList(searchName);
    if (foundContact) {
        cout << "Found contact - Name: " << foundContact->name << ", Phone: " << foundContact->phone << endl;
    } else {
        cout << "Contact not found!" << endl;
    }

    contactBook.deleteFromHead();
    contactBook.deleteFromTail();

    cout << "\nContact Book after deletion:" << endl;
    contactBook.display();

    return 0;
}
#include <iostream>
using namespace std;
// aser 
struct Book {
    int id; 
    string title;
    Book* next; 

    Book(int bookId, string bookTitle) : id(bookId), title(bookTitle), next(nullptr) {}
};

class Library {
public:
    Book* head;
    Book* tail;
    int size; 

    Library() : head(nullptr), tail(nullptr), size(0) {}

    bool isEmpty() {
        return head == nullptr;
    }

    void addToHead(int id, string title) {
        Book* newBook = new Book(id, title);
        if (isEmpty()) {
            head = tail = newBook;
        } else {
            newBook->next = head;
            head = newBook;
        }
        size++;
    }

    void addToTail(int id, string title) {
        Book* newBook = new Book(id, title);
        if (isEmpty()) {
            head = tail = newBook;
        } else {
            tail->next = newBook;
            tail = newBook;
        }
        size++;
    }

    void display() {
        if (isEmpty()) {
            cout << "The library is empty.\n";
            return;
        }
        Book* current = head;
        while (current != nullptr) {
            cout << "ID: " << current->id << ", Title: " << current->title << endl;
            current = current->next;
        }
    }

    void deleteFromHead() {
        if (isEmpty()) {
            cout << "The library is empty. Cannot delete from head.\n";
            return;
        }
        Book* temp = head;
        head = head->next;
        delete temp;
        size--;
        if (head == nullptr) {
            tail = nullptr;
        }
    }

    void deleteFromTail() {
        if (isEmpty()) {
            cout << "The library is empty. Cannot delete from tail.\n";
            return;
        }
        if (head == tail) { 
            delete head;
            head = tail = nullptr;
        } else {
            Book* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
        size--;
    }

    int count() {
        return size;
    }

    bool findInList(int id) {
        Book* current = head;
        while (current != nullptr) {
            if (current->id == id) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    ~Library() {
        while (!isEmpty()) {
            deleteFromHead();
        }
    }
};

int main() {
    // Library library;

    // library.addToHead(1, "The Great Gatsby");
    // library.addToTail(2, "1984");
    // library.addToTail(3, "To Kill a Mockingbird");

    // library.display();

    // library.deleteFromHead();
    // library.display();

    // library.deleteFromTail();
    // library.display();

    // library.addToHead(4, "Moby Dick");
    // library.display();


    // int searchId = 2;
    // cout << "\nSearching for book with ID " << searchId << ": ";
    // if (library.findInList(searchId)) {
    //     cout << "Found!\n";
    // } else {
    //     cout << "Not found.\n";
    // }

    return 0;
}

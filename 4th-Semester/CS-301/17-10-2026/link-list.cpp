
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }

    // Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }

    // Delete the first node
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete a node by its value
    void deleteByValue(int value) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        // If the first node contains the value
        if (head->data == value) {
            deleteFromBeginning();
            return;
        }

        Node* current = head;

        while (current->next != nullptr &&
               current->next->data != value) {
            current = current->next;
        }

        if (current->next == nullptr) {
            cout << value << " not found.\n";
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    // Search for a value
    bool search(int value) {
        Node* current = head;

        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }

            current = current->next;
        }

        return false;
    }

    // Display all nodes
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* current = head;

        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }

        cout << "nullptr\n";
    }

    // Release all dynamically allocated nodes
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;

    list.insertAtBeginning(20);
    list.insertAtBeginning(10);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    cout << "Original list: ";
    list.display();

    cout << "\nSearching for 30: ";
    cout << (list.search(30) ? "Found" : "Not found") << '\n';

    list.deleteFromBeginning();
    cout << "After deleting the first node: ";
    list.display();

    list.deleteByValue(30);
    cout << "After deleting value 30: ";
    list.display();

    return 0;
}

#include <iostream>
using namespace std;

// Define the structure for a node in the doubly linked list.
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void addElement(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void displayList() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void deleteElement(int val) {
        Node* current = head;
        while (current) {
            if (current->data == val) {
                if (current == head) {
                    head = current->next;
                    if (head)
                        head->prev = nullptr;
                } else if (current == tail) {
                    tail = current->prev;
                    tail->next = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return; // Found and deleted the element, so we can return.
            }
            current = current->next;
        }
        cout << "Element not found in the list." << endl;
    }
};

int main() {
    DoublyLinkedList myList;

    while (true) {
        int val;
        cout << "Enter an element (-1 to display, -2 to exit): ";
        cin >> val;

        if (val == -2) {
            break;
        } else if (val == -1) {
            cout << "List elements: ";
            myList.displayList();
        } else {
            myList.addElement(val);
        }
    }

    int deleteVal;
    cout << "Enter the value to delete: ";
    cin >> deleteVal;
    myList.deleteElement(deleteVal);

    cout << "Updated list: ";
    myList.displayList();

    return 0;
}

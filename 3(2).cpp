#include <iostream>
using namespace std;

// Define the structure for a node in the doubly linked list.
struct Node {
    char data;
    Node* next;
    Node* prev;
    Node(char val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void addElement(char val) {
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

    bool isPalindrome() {
        if (!head)
            return false; // An empty list is not a palindrome

        Node* front = head;
        Node* back = tail;

        while (front != back && back->next != front) {
            if (front->data != back->data)
                return false;
            front = front->next;
            back = back->prev;
        }

        return true;
    }
};

int main() {
    DoublyLinkedList myList;

    string input;
    cout << "Enter a string: ";
    cin >> input;

    for (char ch : input) {
        myList.addElement(ch);
    }

    if (myList.isPalindrome()) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}

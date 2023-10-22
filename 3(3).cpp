#include <iostream>
using namespace std;
#include <unordered_set>

// Node of a doubly linked list 
struct Node {
  int data;
  Node* next;
  Node* prev;
};

// Function to remove duplicates from a doubly linked list
void removeDuplicates(Node* head) {

  // Pointer to traverse the linked list
  Node* current = head;  

  // Hash to store visited nodes
  unordered_set<int> visited;  

  // Traverse the list
  while(current != NULL) {

    // If current element is seen before
    if(visited.find(current->data) != visited.end()) {

      // Remove the node
      Node* temp = current;
      current->prev->next = current->next;
      current->next->prev = current->prev; 
      delete temp;

    }
    else { // Else mark it as visited and increment pointer
      visited.insert(current->data);
      current = current->next;
    }
  }
}

// Function to print the doubly linked list 
void printList(Node* node) {
  while (node != NULL) {
    cout << node->data << " ";
    node = node->next;
  }
}

// Driver code
int main() {

  // Create the doubly linked list
  Node* head = new Node();
  head->data = 1;

  head->next = new Node();
  head->next->data = 2;

  head->next->next = new Node(); 
  head->next->next->data = 3;

  head->next->next->next = new Node();
  head->next->next->next->data = 3; 

  head->next->next->next->next = new Node();
  head->next->next->next->next->data = 4;

  cout << "Original List: ";
  printList(head);

  // Remove duplicates
  removeDuplicates(head);

  cout << "\nAfter removing duplicate elements: ";
  printList(head);

  return 0;
}

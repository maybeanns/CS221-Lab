#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

Node *getMid(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node *merge(Node *left, Node *right)
{
    if (left == nullptr)
    {
        return right;
    }
    if (right == nullptr)
    {
        return left;
    }

    Node *result;

    if (left->data <= right->data)
    {
        result = left;
        result->next = merge(left->next, right);
        result->next->prev = result;
    }
    else
    {
        result = right;
        result->next = merge(left, right->next);
        result->next->prev = result;
    }

    return result;
}

Node *mergeSort(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *mid = getMid(head);
    Node *nextToMid = mid->next;
    mid->next = nullptr;
    nextToMid->prev = nullptr;

    Node *left = mergeSort(head);
    Node *right = mergeSort(nextToMid);

    return merge(left, right);
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // 10 20 8 17 5 13 4
    Node *head = new Node{10, nullptr, nullptr};
    head->next = new Node{20, head, nullptr};
    head->next->next = new Node{8, head->next, nullptr};
    head->next->next->next = new Node{17, head->next->next, nullptr};
    head->next->next->next->next = new Node{5, head->next->next->next, nullptr};
    head->next->next->next->next->next = new Node{13, head->next->next->next, nullptr};
    head->next->next->next->next->next->next = new Node{4, head->next->next->next, nullptr};

    cout << "Original List: ";
    printList(head);

    head = mergeSort(head);
    cout << "Sorted List: ";
    printList(head);

    return 0;
}

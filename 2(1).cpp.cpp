#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node()
    {
        data = 0;
        next = nullptr;
    }
    node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class list
{
public:
    list()
    {
        head = nullptr;
    }

    node *head;

    void insert(int val)
    {
        node *newnode = new node(val);
        if (head == NULL)
        {
            head = newnode;
            return;
        }
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    void display()
    {
        node *temp = head;
        if (head == nullptr)
        {
            cout << "Empty!" << endl;
        }
        while (temp->next != 0)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void deletenode(int key)
    {
        if (head == nullptr)
        {
            cout << "List is empty, cannot delete." << endl;
            return;
        }

        if (head->data == key)
        {
            node *temp = head;
            head = head->next;
            delete temp;
            cout << "Node with key " << key << " deleted." << endl;
            return;
        }

        node *temp = head;
        while (temp->next != nullptr)
        {
            if (temp->next->data == key)
            {
                node *nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete nodeToDelete;
                cout << "Node with key " << key << " deleted." << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Node with key " << key << " not found in the list." << endl;
    }
};
void  countnodes(node * head)
    {
        int count=0;
        node* temp = head;
        while (temp != nullptr)
        {
            count++;
            temp= temp->next;
        }
        cout<< count;
    }
    
int main()
{
    list l1;
    int count = 0;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);
    l1.display();
    l1.deletenode(3);
    l1.display();

    countnodes(l1.head);
    // count<<"No. of nodes"<<x<<endl;
    return 0;
}
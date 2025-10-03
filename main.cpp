#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};


// func protos
void insertF(Node*& head, float val);
void insertT(Node*& head, float val);
void deleteNode(Node*& head, int pos);
void deleteList(Node*& head);
void insertN(Node*& head, float val, int pos);
void output(Node *);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i =0; i < SIZE; i++)
    {
        int tmp_val = rand() % 100;
        insertF(head, tmp_val);
    }



    output(head);

    // deleting a node
    Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    deleteNode(head, entry);
    output(head);

    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    insertN(head, 10000, entry);

    output(head);

    // deleting the linked list
    deleteList(head);

    output(head);

    return 0;
}

// new head node
void insertF(Node*& head, float val)
{
    Node *newNode = new Node; // allocate memory
    newNode->value = val;
    newNode->next = head; // assign new node
    head = newNode; // update head
}

// adds tail node
void insertT(Node*& head, float val)
{
    Node *newNode = new Node;
    newNode->value = val;
    newNode->next = nullptr; // tail is now null

    // check if empty linked list
    if (!head)
    {
        head = newNode;
        return; // get out of method
    }

    Node *current = head;
    while (current->next)
    {
        current = current->next; // moves forward
    }

    current->next = newNode;
}

// delete any node at some position
void deleteNode (Node*& head, int pos)
{
    // check valid pos
    if (!head || pos < 1)
        return;

    
    
    Node* current = head;
    if (pos == 1)
    {
        head = head->next;
        delete current; // free up mem
        return;
    }

    Node *previous = nullptr;

    for (int i = 1; current && i < pos; i++)
    {
        previous = current;
        current = current->next; // traverse node

    }

    if (!current)
        return;

    previous->next = current->next; // bypass the node so you can delete it 
    delete current; // free mem
}

void deleteList(Node*& head)
{
    Node *current = head;
    while (current)
    {
        Node *temp = current; // this keeps track of node i think
        current = current -> next; // traverse
        delete temp; // free mem
    }
    head = nullptr; // this makes list empty 
}

// insert node at specified position
void insertN(Node*& head, float val, int pos)
{
    // check valid pos
    if (!head || pos < 1)
        return;
    
    Node* current = head;
    for (int i = 1; current && i < pos; i++)
    {
        current = current->next; // traverse
    }

    if (!current) 
        return;
    
    Node *newNode = new Node;
    newNode->value = val;
    newNode->next = current->next;
    current->next = newNode;
}


void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}
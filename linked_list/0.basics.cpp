/**
 * Linked List: collection of nodes
 *  # pros:
 *      1. Non-contiguous memory location
 *      2. no memory wastage
 *      3. insertion without shifting elements
 *      4. dynamically grow and shrink
 *      5. insert and delete at runtime
 *  # cons:
 *
 *
 * Types:
 *  1. singly linked list
 *  2. circular singly linked list
 *  3. doubly linked list
 *  4. circular doubly linked list
 *
 */

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    print(first);

    return 0;
}
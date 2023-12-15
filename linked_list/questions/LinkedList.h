#if !defined(LinkedList_H)
#define LinkedList_H

#include <iostream>
using namespace std;

int list_size = 0;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        cout << "Destructor called for " << this->data << endl;
    }
};

void insertAtTail(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    list_size++;
}

void deleteFromTail(Node *&head)
{
    if (head == NULL)
    {
        cout << "Linked List is already empty!" << endl;
        return;
    }
    Node *prev = NULL;
    Node *curr = head;
    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;
    delete curr;
    list_size--;
}

void reverseLL(Node *&head)
{
    Node *prev = NULL, *curr = head, *nextNode = NULL;

    while (curr != NULL)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    head = prev;
}

void printLL(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

#endif // LinkedList_H

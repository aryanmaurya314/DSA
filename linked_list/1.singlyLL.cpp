#include <iostream>
using namespace std;

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

void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        tail = newNode;
    }
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        tail->next = newNode;
    }
    tail = newNode;
}

int getLength(Node *&head)
{
    Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

void insertAtPosition(Node *&head, Node *&tail, int pos, int data)
{
    int length = getLength(head);
    if (pos < 1 || pos > length + 1)
    {
        cout << "Please enter a valid position." << endl;
        return;
    }
    if (pos == 1)
    {
        insertAtHead(head, tail, data);
    }
    else if (pos == length + 1)
    {
        insertAtTail(head, tail, data);
    }
    else
    {
        // insert at a specific position
        Node *prev = NULL;
        Node *curr = head;
        while (pos != 1)
        {
            prev = curr;
            curr = curr->next;
            pos--;
        }
        Node *newNode = new Node(data);
        prev->next = newNode;
        newNode->next = curr;
    }
}

void deleteFromHead(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "LL is already empty." << endl;
        return;
    }
    if (head == tail)
    {
        Node *temp = head;
        delete temp;
        head = NULL;
        tail = head;
        return;
    }
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
}

void deleteFromTail(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "LL is already empty." << endl;
        return;
    }
    if (head == tail)
    {
        Node *temp = head;
        delete temp;
        head = NULL;
        tail = head;
        return;
    }

    Node *prev = head;
    while (prev->next != tail)
    {
        prev = prev->next;
    }

    prev->next = NULL;
    delete tail;
    tail = prev;
}

void deleteFromPosition(Node *&head, Node *&tail, int pos)
{
    int length = getLength(head);
    if (pos < 1 || pos > length + 1)
    {
        cout << "Please enter a valid position." << endl;
        return;
    }
    if (head == NULL)
    {
        cout << "LL is already empty." << endl;
        return;
    }

    if (pos == 1)
    {
        deleteFromHead(head, tail);
    }
    else if (pos == length)
    {
        deleteFromTail(head, tail);
    }
    else
    {
        // delete from position
        Node *prev = NULL;
        Node *curr = head;
        while (pos != 1)
        {
            prev = curr;
            curr = curr->next;
            pos--;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    // insertAtTail(head, tail, 70);
    // insertAtTail(head, tail, 80);
    // insertAtPosition(head, tail, 6, 101);

    printLL(head);

    deleteFromHead(head, tail);
    printLL(head);
    deleteFromTail(head, tail);
    printLL(head);
    deleteFromPosition(head, tail, 1);
    printLL(head);

    return 0;
}
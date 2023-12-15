#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node()
    {
        cout << "Destructor called for " << this->data << endl;
    }
};

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

void printDLL(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = head;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = head;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insertAtPosition(Node *&head, Node *&tail, int pos, int data)
{
    int length = getLength(head);
    if (pos < 1 || pos > length + 1)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = head;
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
        // insert at position
        Node *newNode = new Node(data);
        Node *curr = head;

        while (pos != 1)
        {
            curr = curr->next;
            pos--;
        }

        newNode->prev = curr->prev;
        curr->prev->next = newNode;
        curr->prev = newNode;
        newNode->next = curr;
    }
}

void deleteNode(Node *&head, Node *&tail, int pos)
{
    if (head == NULL)
    {
        cout << "DLL is already empty!" << endl;
        return;
    }
    int length = getLength(head);
    if (pos < 1 || pos > length)
    {
        cout << "Invalid postion!" << endl;
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

    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }
    else if (pos == length)
    {
        Node *temp = tail;
        tail = temp->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
    else
    {
        // delete from position
        Node *curr = head;

        while (pos != 1)
        {
            curr = curr->next;
            pos--;
        }

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = head;

    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);
    printDLL(head);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 60);
    printDLL(head);
    cout << "***************************" << endl;
    insertAtPosition(head, tail, 2, 6);
    insertAtPosition(head, tail, 4, 7);
    printDLL(head);
    deleteNode(head, tail, 1);
    printDLL(head);
    deleteNode(head, tail, 7);
    printDLL(head);
    deleteNode(head, tail, 3);
    deleteNode(head, tail, 1);
    deleteNode(head, tail, 1);
    deleteNode(head, tail, 1);
    deleteNode(head, tail, 1);
    deleteNode(head, tail, 1);
    printDLL(head);
    deleteNode(head, tail, 1);

    cout << sizeof(Node) << endl;

    return 0;
}
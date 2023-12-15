#include <iostream>
#include <vector>
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
};

int getLength(Node *&head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertList(Node *&head, vector<int> &list)
{

    Node *temp = new Node(list[0]);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        Node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }

    for (int i = 1; i < list.size(); i++)
    {
        Node *newNode = new Node(list[i]);

        temp->next = newNode;
        temp = temp->next;
    }
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

Node *findMiddle(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty!" << endl;
        return head;
    }
    if (head->next == NULL)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    vector<int> list = {1, 2, 3, 4, 5, 6, 7, 8};

    Node *head = NULL;

    insertList(head, list);

    printLL(head);

    cout << "Mid of LL: " << findMiddle(head)->data << endl;

    return 0;
}
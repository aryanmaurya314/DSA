#include <iostream>
#include "LinkedList.h"
using namespace std;

void reverseLL(Node *&head)
{
    Node *prevNode = NULL, *nextNode = NULL;
    Node *currNode = head;

    while (currNode != NULL)
    {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    head = prevNode;
}

Node *reverseLL_RE(Node *prev, Node *curr)
{
    if (curr == NULL)
    {
        return prev;
    }

    Node *nextNode = curr->next;
    curr->next = prev;

    return reverseLL_RE(curr, nextNode);
}

int main()
{
    Node *head = NULL;
    insertAtTail(head, 2);
    insertAtTail(head, 4);
    insertAtTail(head, 6);
    insertAtTail(head, 8);

    cout << "Before reverse: ";
    printLL(head);
    // reverseLL(head);
    Node *curr = head, *prev = NULL;
    head = reverseLL_RE(prev, curr);
    cout << "After reverse: ";
    printLL(head);

    return 0;
}
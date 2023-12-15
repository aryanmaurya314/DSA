#include <iostream>
#include "LinkedList.h"
using namespace std;

int getLength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

Node *kGroupReverse(Node *&head, int group)
{
    // base case
    if (head == NULL || head->next == NULL || getLength(head) < group)
    {
        return head;
    }

    Node *prev = NULL, *curr = head, *nextNode = NULL;
    int k = group;
    while (k)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        k--;
    }

    head->next = kGroupReverse(nextNode, group);

    return prev;
}

int main()
{

    Node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    insertAtTail(head, 9);
    insertAtTail(head, 10);
    insertAtTail(head, 11);

    printLL(head);

    int k = 3;
    head = kGroupReverse(head, k);

    printLL(head);

    return 0;
}
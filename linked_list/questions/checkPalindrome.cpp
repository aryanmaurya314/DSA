// LEETCODE: 234
#include <iostream>
#include "LinkedList.h"
using namespace std;

Node *reverseLL(Node *prev, Node *curr)
{
    if (curr == NULL)
    {
        return prev;
    }

    Node *nextNode = curr->next;
    curr->next = prev;

    return reverseLL(curr, nextNode);
}

bool isPalindrome(Node *head)
{
    if (head == NULL)
    {
        return false;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    fast = slow->next;
    slow->next = NULL;
    slow = head;
    printLL(head);
    Node *prev = NULL, *curr = fast;
    fast = reverseLL(prev, curr);
   printLL(fast);
    while (fast != NULL)
    {
        if (slow->data != fast->data)
        {
            return false;
        }
        slow = slow->next;
        fast = fast->next;
    }

    return true;
}

int main()
{
    Node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 3);
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 1);

    printLL(head);
    cout << isPalindrome(head) << endl;
    printLL(head);

    return 0;
}
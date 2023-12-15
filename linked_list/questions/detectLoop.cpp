#include <iostream>
#include "LinkedList.h"
using namespace std;

bool detectLoop(Node *&head)
{
    Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}

Node *startOfLoop(Node *&head)
{
    Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = head;
            break;
        }
    }

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

void removeLoop(Node *&head)
{
    Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = head;
            break;
        }
    }

    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = NULL;
}

int main()
{
    Node *head = NULL;
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 8);
    insertAtTail(head, 7);
    printLL(head);

    head->next->next->next->next->next->next = head->next->next;

    if (detectLoop(head))
    {
        cout << "Loop is present. Loop start data: " << startOfLoop(head)->data << endl;
    }
    else
    {
        cout << "Loop is absent." << endl;
    }

    removeLoop(head);
    printLL(head);

    return 0;
}
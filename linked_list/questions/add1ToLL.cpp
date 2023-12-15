#include <iostream>
#include "LinkedList.h"
using namespace std;

void addOne(Node *&head)
{
    if (head == NULL)
    {
        head = new Node(1);
        return;
    }

    reverseLL(head);

    Node *temp = head;
    int carry = 1;

    while (temp != NULL)
    {
        int value = temp->data + carry;
        int digit = value % 10;
        temp->data = digit;
        carry = value / 10;
        if (carry == 0)
        {
            break;
        }
        if (temp->next == NULL && carry != 0)
        {
            temp->next = new Node(carry);
            break;
        }
        temp = temp->next;
    }

    reverseLL(head);
}

int main()
{
    Node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 9);
    insertAtTail(head, 9);
    printLL(head);
    addOne(head);
    printLL(head);

    return 0;
}
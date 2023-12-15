#include <iostream>
#include "LinkedList.h"
using namespace std;

void skipMdeleteN(Node *&head, int M, int N)
{
    if (head == NULL)
    {
        return;
    }

    Node *curr = head;
    int i = 1;

    while (curr != NULL && i < M)
    {
        curr = curr->next;
        i++;
    }
    if (curr == NULL)
    {
        return;
    }
    Node *temp = curr->next;
    curr->next = NULL;
    int j = 1;

    while (temp != NULL && j <= N)
    {
        Node *delNode = temp;
        temp = temp->next;
        delNode->next = NULL;
        delete delNode;
        j++;
    }
    curr->next = temp;
    skipMdeleteN(temp, M, N);
}

int main()
{
    Node *head = NULL;
    insertAtTail(head, 9);
    insertAtTail(head, 1);
    insertAtTail(head, 3);
    insertAtTail(head, 5);
    insertAtTail(head, 9);
    insertAtTail(head, 4);
    insertAtTail(head, 10);
    // insertAtTail(head, 1);
    cout << "Before deletion: ";
    printLL(head);

    int M = 2, N = 1;

    skipMdeleteN(head, M, N);

    cout << "After deletion: ";
    printLL(head);

    return 0;
}
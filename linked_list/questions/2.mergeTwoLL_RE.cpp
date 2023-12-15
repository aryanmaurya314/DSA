#include <iostream>
#include "LinkedList.h"
using namespace std;

Node *merge(Node *list1, Node *list2)
{
    if (!list1)
    {
        return list2;
    }
    if (!list2)
    {
        return list1;
    }
    Node *head = NULL;
    if (list1->data < list2->data)
    {
        head = list1;
        head->next = merge(list1->next, list2);
    }
    else
    {
        head = list2;
        head->next = merge(list1, list2->next);
    }

    return head;
}

int main()
{

    Node *list1 = NULL;
    insertAtTail(list1, 2);
    insertAtTail(list1, 4);
    insertAtTail(list1, 6);
    insertAtTail(list1, 8);
    Node *list2 = NULL;
    insertAtTail(list2, 1);
    insertAtTail(list2, 3);
    insertAtTail(list2, 5);
    insertAtTail(list2, 7);
    insertAtTail(list2, 9);

    cout << "List1: ";
    printLL(list1);
    cout << endl;

    cout << "List2: ";
    printLL(list2);
    cout << endl;

    Node *head = merge(list1, list2);

    cout << "Merged List: ";
    printLL(head);
    cout << endl;

    return 0;
}
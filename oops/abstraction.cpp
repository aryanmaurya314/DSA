//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
};

void print(struct Node *Node)
{
    while (Node != NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
private:
    Node *reverseLL(Node *&head)
    {
        Node *curr = head, *prev = NULL, *nextNode = NULL;

        while (curr)
        {
            cout << "1. ==> " << endl;
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

public:
    struct Node *mergeResult(Node *node1, Node *node2)
    {
        node1 = reverseLL(node1);
        node2 = reverseLL(node2);

        if (node1 && !node2)
            return node1;
        if (!node1 && node2)
            return node2;

        Node *head = NULL;

        if (node1->data > node2->data)
        {
            head = node1;
            node1 = node1->next;
            head->next = node2;
        }
        else
        {
            head = node2;
            node2 = node2->next;
            head->next = node1;
        }

        while (node1 && node2)
        {
            cout << "2. ==> " << endl;
            if (node1->data > node2->data)
            {
                while (node1->next && node1->next->data > node2->data)
                {
                    cout << "3. ==> " << endl;
                    node1 = node1->next;
                }
                Node *temp = node1;
                node1 = node1->next;
                temp->next = node2;
            }
            else
            {
                while (node2->next && node2->next->data > node1->data)
                {
                    cout << "4. ==> " << endl;
                    node2 = node2->next;
                }
                Node *temp = node2;
                node2 = node2->next;
                temp->next = node1;
            }
        }

        return head;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int nA;
        cin >> nA;
        int nB;
        cin >> nB;

        struct Node *headA = NULL;
        struct Node *tempA = headA;

        for (int i = 0; i < nA; i++)
        {
            int ele;
            cin >> ele;
            if (headA == NULL)
            {
                headA = tempA = newNode(ele);
            }
            else
            {
                tempA->next = newNode(ele);
                tempA = tempA->next;
            }
        }

        struct Node *headB = NULL;
        struct Node *tempB = headB;

        for (int i = 0; i < nB; i++)
        {
            int ele;
            cin >> ele;
            if (headB == NULL)
            {
                headB = tempB = newNode(ele);
            }
            else
            {
                tempB->next = newNode(ele);
                tempB = tempB->next;
            }
        }

        Solution ob;
        struct Node *result = ob.mergeResult(headA, headB);

        print(result);
        cout << endl;
    }
}

// } Driver Code Ends
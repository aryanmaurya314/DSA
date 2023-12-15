#if !defined(TREE_H)
#define TREE_H

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    // Initial step
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        // STEP A: store q front in temp
        Node *temp = q.front();
        // STEP B: remove front of q
        q.pop();
        if (temp == NULL)
        {
            // print next level in next line
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            // STEP C: print temp data
            cout << temp->data << " ";
            // STEP D: insert left and right of temp to q if exists
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

Node *buildTree()
{
    int data;
    cout << "Enter the data: " << endl;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    // STEP A: create node
    Node *root = new Node(data);
    // STEP B: build left part
    cout << "Left of " << data << " node ";
    root->left = buildTree();
    // STEP C: build right part
    cout << "Right of " << data << " node ";
    root->right = buildTree();

    return root;
}

#endif // TREE_H

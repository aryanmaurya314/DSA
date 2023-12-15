#if !defined(TREE_H)
#define TREE_H

#include <iostream>
#include <vector>
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

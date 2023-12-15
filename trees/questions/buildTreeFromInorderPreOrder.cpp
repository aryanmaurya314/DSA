#include <iostream>
#include "Tree.h"
using namespace std;

int findPosition(int inorder[], int s, int e, int data)
{

    for (int i = s; i <= e; i++)
    {
        if (inorder[i] == data)
        {
            return i;
        }
    }

    return -1;
}

Node *buildTreeFromInorderPreorder(int inorder[], int preorder[], int n, int &preIndex, int inorderStart, int inorderEnd)
{
    // base case
    if (preIndex >= n || inorderStart > inorderEnd)
    {
        return NULL;
    }

    // STEP A: find root node data and create
    int rootData = preorder[preIndex++];
    Node *root = new Node(rootData);
    // STEP B: find root position
    int pos = findPosition(inorder, inorderStart, inorderEnd, rootData);

    // STEP C: build left subtree using recursion
    root->left = buildTreeFromInorderPreorder(inorder, preorder, n, preIndex, inorderStart, pos - 1);

    // STEP D: build right subtree using recursion
    root->right = buildTreeFromInorderPreorder(inorder, preorder, n, preIndex, pos + 1, inorderEnd);

    return root;
}

int main()
{

    int inorder[] = {40, 20, 50, 10, 60, 30, 70, 80};
    int preorder[] = {10, 20, 40, 50, 30, 60, 70, 80};
    int n = 8;
    int preIndex = 0;
    int inorderStart = 0;
    int inorderEnd = n - 1;

    Node *root = buildTreeFromInorderPreorder(inorder, preorder, n, preIndex, inorderStart, inorderEnd);

    levelOrderTraversal(root);

    return 0;
}
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

Node *buildTreeFromInorderPostorder(int inorder[], int postorder[], int &postIndex, int inorderStart, int inorderEnd)
{
    // base case
    if (postIndex < 0 || inorderStart > inorderEnd)
    {
        return NULL;
    }

    // STEP A: find root node data and create
    int rootData = postorder[postIndex--];
    Node *root = new Node(rootData);
    // STEP B: find root position
    int pos = findPosition(inorder, inorderStart, inorderEnd, rootData);

    // LRN: root node create karne ke baad pahle right subtree banao then left subtree
    // STEP C: build right subtree using recursion
    root->right = buildTreeFromInorderPostorder(inorder, postorder, postIndex, pos + 1, inorderEnd);

    // STEP D: build left subtree using recursion
    root->left = buildTreeFromInorderPostorder(inorder, postorder, postIndex, inorderStart, pos - 1);

    return root;
}

int main()
{

    int inorder[] = {40, 20, 50, 10, 60, 30, 70, 80};
    int postorder[] = {40, 50, 20, 60, 80, 70, 30, 10};
    int n = 8;
    int postIndex = n - 1;
    int inorderStart = 0;
    int inorderEnd = n - 1;

    Node *root = buildTreeFromInorderPostorder(inorder, postorder, postIndex, inorderStart, inorderEnd);

    levelOrderTraversal(root);

    return 0;
}
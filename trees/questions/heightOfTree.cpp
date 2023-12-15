#include <iostream>
#include "Tree.h"
using namespace std;

int heightOfTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    // root + max of height of left and height of right
    return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
}

int main()
{
    // tree: 20 30 50 -1 60 -1 -1 40 -1 -1 100 -1 -1
    Node *root = buildTree();

    levelOrderTraversal(root);

    cout << "Height of tree: " << heightOfTree(root) << endl;

    return 0;
}
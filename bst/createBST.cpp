#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBST(Node *root, int data)
{ // TC avg case = O(logn) | skew tree = O(n
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data < root->data)
    {
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void createBST(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    cout << "Printing BST level-order: " << endl;
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << node->data << " ";
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
    }
    cout << endl;
}

void inOrder(Node *root)
{ // LNR
    if (!root)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node *root)
{ // NLR
    if (!root)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{ // LRN
    if (!root)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

Node *findTragetInBST(Node *root, int target)
{
    if (!root)
    {
        return NULL;
    }

    if (target == root->data)
    {
        return root;
    }

    if (target < root->data)
    {
        return findTragetInBST(root->left, target);
    }

    return findTragetInBST(root->right, target);
}

int findMinimum(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }

    while (root->left)
    {
        root = root->left;
    }

    return root->data;
}

int findMaximum(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }

    while (root->right)
    {
        root = root->right;
    }

    return root->data;
}

void inOrderPredecessor(Node *root, int target)
{
}

Node *deleteNodeInBST(Node *root, int target)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }

    // STEP 1: find target node
    Node *targetNode = findTragetInBST(root, target);
    // delete targetNode
    if (!targetNode->left && !targetNode->right)
    {
        delete targetNode;
        return NULL;
    }
    else if (!targetNode->left && targetNode->right)
    {
        Node *right = targetNode->right;
        delete targetNode;
        return right;
    }
    else if (targetNode->left && !targetNode->right)
    {
        Node *left = targetNode->left;
        delete targetNode;
        return left;
    }
    else
    { // both child exist
      // find inorder predecessor of left subtree -> left subtree max value
        int inorderPre = findMaximum(targetNode->left);
        targetNode->data = inorderPre;
        targetNode->left = deleteNodeInBST(targetNode->left, inorderPre);
        return root;
    }
}

int main()
{
    // BST: 500 150 250 600 650 170 90 220 501 1000 111 999 -1
    // BST: 10 20 5 11 17 2 4 8 6 25 15 -1
    // BST: 100 50 150 40 60 175 110 -1
    Node *root = NULL;

    createBST(root);

    levelOrder(root);

    // NOTE: inOrder travrsal of BST is always sorted
    cout << "Printing inOrder: ";
    inOrder(root);
    cout << endl;

    cout << "Printing preOrder: ";
    preOrder(root);
    cout << endl;

    cout << "Printing postOrder: ";
    postOrder(root);
    cout << endl;

    // TC avg case = O(logn) | skew tree = O(n)
    int target = 18;
    bool isFound = findTragetInBST(root, target);
    cout << "Is target found: " << (isFound ? "True" : "False") << endl;

    cout << "Minimum value of BST: " << findMinimum(root) << endl;
    cout << "Maximum value of BST: " << findMaximum(root) << endl;

    int deleteTarget = 100;
    deleteNodeInBST(root, deleteTarget);
    cout << "After deleting " << deleteTarget << " : " << endl;
    levelOrder(root);

    return 0;
}
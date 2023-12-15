#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void inOrderTraversal(Node *root)
{
    // LNR
    if (root == NULL)
    {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

Node *createBstUsingInorder(vector<int> &inorder, int s, int e)
{
    // base case
    if (s > e)
    {
        return NULL;
    }

    int mid = (s + e) / 2;

    Node *root = new Node(inorder[mid]);

    root->left = createBstUsingInorder(inorder, s, mid - 1);
    root->right = createBstUsingInorder(inorder, mid + 1, e);

    return root;
}

Node *createBstUsingPreorder(vector<int> &preorder, int mini, int maxi, int &index)
{
    // base case
    if (index >= preorder.size())
    {
        return NULL;
    }

    Node *root = NULL;

    int currElem = preorder[index];
    if (currElem > mini && currElem < maxi)
    {
        root = new Node(currElem);
        index++;
        root->left = createBstUsingPreorder(preorder, mini, currElem, index);
        root->right = createBstUsingPreorder(preorder, currElem, maxi, index);
    }

    return root;
}

void bstToDLL(Node *root, Node *&head)
{
    if (!root)
    {
        return;
    }
    // RNL
    // R
    bstToDLL(root->right, head);
    // N
    root->right = head;
    if (head)
    {
        head->left = root;
    }
    head = root;
    // L
    bstToDLL(root->left, head);
}

Node *dllToBST(Node *&head, int n)
{
    if (!head || n <= 0)
    {
        return NULL;
    }
    // LNR
    // L
    Node *leftSubtree = dllToBST(head, n / 2);
    // N
    Node *root = head;
    root->left = leftSubtree;
    head = head->right;
    // R
    Node *rightSubtree = dllToBST(head, n - n / 2 - 1);
    root->right = rightSubtree;
    return root;
}

void printDLL(Node *&head)
{
    cout << "Printing DLL: ";
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
}

void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

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

int main()
{
    // inorder: 10 20 30 40 50 60 70
    // Create Balanced BST
    // vector<int> inorder = {10, 20, 30, 40, 50, 60, 70};
    // inorder = {5, 50, 60, 100, 200, 250, 300};
    // inorder = {25, 30, 40, 50, 55, 60, 70, 80};
    // int s = 0, e = inorder.size() - 1;
    // Node *root = createBstUsingInorder(inorder, s, e);

    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    int mini = INT_MIN, maxi = INT_MAX, index = 0;
    Node *root = createBstUsingPreorder(preorder, mini, maxi, index);

    cout << "Printing inorder traversal: ";
    inOrderTraversal(root);
    cout << endl;
    cout << "Printing levelOrder traversal: " << endl;
    levelOrder(root);
    cout << endl;

    // Node *head = NULL;
    // bstToDLL(root, head);
    // printDLL(head);

    // Node *root1 = dllToBST(head, 8);
    // cout << "Printing inorder traversal of root1: ";
    // inOrderTraversal(root1);
    // cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

Node *createTree()
{
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *root = new Node(data);

    root->left = createTree();
    root->right = createTree();

    return root;
}

void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *&node = q.front();
        q.pop();

        if (!node)
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

    preOrder(root->left);
    preOrder(root->right);
    cout << root->data << " ";
}

void inOrder(Node *root)
{ // LNR
    if (!root)
    {
        return;
    }

    preOrder(root->left);
    cout << root->data << " ";
    preOrder(root->right);
}

void leftView(Node *root, int level, int &count)
{
    if (!root)
    {
        return;
    }

    if (level == count)
    {
        count++;
        cout << root->data << " ";
    }

    leftView(root->left, level + 1, count);
    leftView(root->right, level + 1, count);
}

void rightView(Node *root, int level, int &count)
{
    if (!root)
    {
        return;
    }

    if (level == count)
    {
        count++;
        cout << root->data << " ";
    }

    rightView(root->right, level + 1, count);
    rightView(root->left, level + 1, count);
}

void topView(Node *root)
{
    map<int, int> viewMap;      // {xDistance, root->data}
    queue<pair<Node *, int>> q; // {root, xDistance}
    q.push({root, 0});

    while (!q.empty())
    {
        auto front = q.front();
        q.pop();

        Node *node = front.first;
        int xDistance = front.second;

        if (viewMap.find(xDistance) == viewMap.end())
        {
            viewMap[xDistance] = node->data;
        }

        if (node->left)
        {
            q.push({node->left, xDistance - 1});
        }
        if (node->right)
        {
            q.push({node->right, xDistance + 1});
        }
    }

    for (auto it : viewMap)
    {
        cout << it.second << " ";
    }
}

void bottomView(Node *root)
{
    map<int, int> viewMap;      // {xDistance, root->data}
    queue<pair<Node *, int>> q; // {root, xDistance}
    q.push({root, 0});

    while (!q.empty())
    {
        auto front = q.front();
        q.pop();

        Node *node = front.first;
        int xDistance = front.second;

        viewMap[xDistance] = node->data;

        if (node->left)
        {
            q.push({node->left, xDistance - 1});
        }
        if (node->right)
        {
            q.push({node->right, xDistance + 1});
        }
    }

    for (auto it : viewMap)
    {
        cout << it.second << " ";
    }
}

void leftBoundary(Node *root)
{
    if (!root || (!root->left && !root->right))
    {
        return;
    }

    cout << root->data << " ";

    if (root->left)
    {
        leftBoundary(root->left);
    }
    else
    {
        leftBoundary(root->right);
    }
}

void leafNodes(Node *root)
{
    if (!root)
    {
        return;
    }

    if (!root->left && !root->right)
    {
        cout << root->data << " ";
    }

    leafNodes(root->left);
    leafNodes(root->right);
}

void rightBoundary(Node *root)
{
    if (!root || (!root->left && !root->right))
    {
        return;
    }

    if (root->right)
    {
        rightBoundary(root->right);
    }
    else
    {
        rightBoundary(root->left);
    }

    cout << root->data << " ";
}

void boundaryTraversal(Node *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << " ";
    leftBoundary(root->left);
    leafNodes(root->left);
    leafNodes(root->right);
    rightBoundary(root->right);
}

int main()
{
    // tree: 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1
    Node *root = createTree();

    levelOrder(root);

    // cout << "Printing left view: ";
    // int level = 0, count = 0;
    // leftView(root, level, count);
    // cout << endl;

    // cout << "Printing right view: ";
    // int level = 0, count = 0;
    // rightView(root, level, count);
    // cout << endl;

    // cout << "Printing top view: ";
    // topView(root);
    // cout << endl;

    // cout << "Printing bottom view: ";
    // bottomView(root);
    // cout << endl;

    cout << "Printing boundary: ";
    boundaryTraversal(root);
    cout << endl;

    return 0;
}
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include "Tree.h"
using namespace std;

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

void inOrderTraversal(Node *root)
{
    // Base case
    if (root == NULL)
    {
        return;
    }
    // LNR
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node *root)
{
    // Base case
    if (root == NULL)
    {
        return;
    }
    // NLR
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    // Base case
    if (root == NULL)
    {
        return;
    }
    // LRN
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void diagonalTraversal(Node *root)
{
    map<int, vector<int>> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto &front = q.front();
        q.pop();
        int &distance = front.second;
        Node *&node = front.first;
        mp[distance].push_back(node->data);

        if (node->left)
        {
            q.push({node->left, distance - 1});
        }
        if (node->right)
        {
            q.push({node->right, distance});
        }
    }

    for (auto it : mp)
    {
        cout << "diagonal " << it.first << ": ";
        auto &currDiagonal = it.second;

        for (int a : currDiagonal)
        {
            cout << a << " ";
        }
        cout << endl;
    }
}

void diagonalTraversalWithoutMap(Node *root)
{
    queue<Node *> q;
    q.push(root);

    int dc = 0;

    while (!q.empty())
    {
        Node *&node = q.front();
        q.pop();
        cout << "diagonal " << dc++ << ": ";
        while (node)
        {
            cout << node->data << " ";
            if (node->left)
            {
                q.push(node->left);
            }
            node = node->right;
        }
        cout << endl;
    }
}

void zigZagTraversal(Node *root)
{
    vector<vector<int>> ans;
    queue<Node *> q;
    q.push(root);

    bool LtoRdir = true;

    while (!q.empty())
    {
        int width = q.size();
        vector<int> currLevel(width);
        for (int i = 0; i < width; i++)
        {
            Node *&node = q.front();
            q.pop();
            int index = LtoRdir ? i : width - i - 1;
            currLevel[index] = node->data;
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        // toggle direction of traversal
        LtoRdir = !LtoRdir;
        ans.push_back(currLevel);
    }

    int level = 0;
    for (auto curr : ans)
    {
        cout << "Level " << level++ << ": ";
        for (int a : curr)
        {
            cout << a << " ";
        }
        cout << endl;
    }
}

void verticalTraversal(Node *root)
{
    queue<pair<Node *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    map<int, map<int, multiset<int>>> mp;

    while (!q.empty())
    {
        auto &front = q.front();
        q.pop();
        Node *&node = front.first;
        auto &coors = front.second;
        int &row = coors.first;
        int &col = coors.second;
        mp[col][row].insert(node->data);
        if (node->left)
        {
            q.push({node->left, {row + 1, col - 1}});
        }
        if (node->right)
        {
            q.push({node->right, {row + 1, col + 1}});
        }
    }

    // vector<vector<int>> ans;
    for (auto it : mp)
    {
        auto rLines = it.second;
        // vector<int> vLine;
        cout << "vertical " << it.first << ": ";
        for (auto rLine : rLines)
        {
            auto mset = rLine.second;
            // vLine.insert(vLine.end(), mset.begin(), mset.end());
            for (int a : mset)
            {
                cout << a << " ";
            }
        }

        // ans.push_back(vLine);
        cout << endl;
    }
}

int main()
{
    // tree: 20 30 50 -1 60 -1 -1 40 -1 -1 100 -1 -1
    Node *root = buildTree();

    // cout << "Printing levelOrderTraversal of the tree: " << endl;
    levelOrderTraversal(root);
    // cout << "Printing inOrderTraversal of the tree: ";
    // inOrderTraversal(root);
    // cout << endl;
    // cout << "Printing preOrderTraversal of the tree: ";
    // preOrderTraversal(root);
    // cout << endl;
    // cout << "Printing postOrderTraversal of the tree: ";
    // postOrderTraversal(root);
    // cout << endl;

    // cout << "Printing diagonalTraversal of the tree: " << endl;
    // diagonalTraversal(root);
    // cout << endl;

    // cout << "Printing diagonalTraversalWithoutMap of the tree: " << endl;
    // diagonalTraversalWithoutMap(root);
    // cout << endl;

    cout << "Printing zigZagTraversal of the tree: " << endl;
    zigZagTraversal(root);
    cout << endl;

    // cout << "Printing verticalTraversal of the tree: " << endl;
    // verticalTraversal(root);
    // cout << endl;

    return 0;
}
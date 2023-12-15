#include <iostream>
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
    this->left = NULL;
    this->right = NULL;
  }
};

Node *insertIntoBST(Node *root, int data)
{
  if (!root)
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

Node *createBST()
{
  int data;
  cin >> data;

  Node *root = NULL;

  while (data != -1)
  {
    root = insertIntoBST(root, data);
    cin >> data;
  }

  return root;
}

void levelOrder(Node *root)
{
  queue<Node *> q;
  q.push(root);
  q.push(NULL);

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
}

// LNR
void inorder(Node *root)
{
  if (!root)
    return;

  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

// NLR
void preorder(Node *root)
{
  if (!root)
    return;

  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

// LRN
void postorder(Node *root)
{
  if (!root)
    return;

  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}

Node *findTargetInBST(Node *root, int target)
{
  if (!root)
    return NULL;

  if (root->data == target)
    return root;

  if (root->data < target)
    return findTargetInBST(root->right, target);

  return findTargetInBST(root->left, target);
}

Node *findMinimum(Node *root)
{
  while (root->left)
    root = root->left;

  return root;
}

Node *findMaximum(Node *root)
{
  while (root->right)
    root = root->right;

  return root;
}

Node *deleteNodeInBST(Node *root, int target)
{
  // base case
  if (!root)
    return NULL;

  if (root->data == target)
  {
    // deleting leaf node
    if (!root->left && !root->right)
    {
      delete root;
      return NULL;
    }
    // if only left subtree present
    if (root->left && !root->right)
    {
      Node *leftSubtree = root->left;
      delete root;
      return leftSubtree;
    }
    // if only right subtree present
    if (!root->left && root->right)
    {
      Node *rightSubtree = root->right;
      delete root;
      return rightSubtree;
    }
    // if both left and right subtree present
    int leftSubtreeMax = findMaximum(root->left)->data;
    root->data = leftSubtreeMax; // replace root data with max of leftSubtree
    root->left = deleteNodeInBST(root->left, leftSubtreeMax);
    return root;
  }
  else if (root->data < target)
  {
    root->right = deleteNodeInBST(root->right, target);
  }
  else
  {
    root->left = deleteNodeInBST(root->left, target);
  }

  return root;
}

Node *createBstUsingInorder(vector<int> &inorder, int s, int e)
{
  // base case
  if (s > e)
    return NULL;

  int mid = s + (e - s) / 2;

  Node *root = new Node(inorder[mid]);

  root->left = createBstUsingInorder(inorder, s, mid - 1);
  root->right = createBstUsingInorder(inorder, mid + 1, e);

  return root;
}

void bstToDLL(Node *root, Node *&head)
{
  if (!root)
  {
    return;
  }

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

void printDLL(Node *&head)
{
  Node *temp = head;
  while (temp)
  {
    cout << temp->data << " ";
    temp = temp->right;
  }
}

int getDllLength(Node *&head)
{
  Node *temp = head;
  int len = 0;
  while (temp)
  {
    len++;
    temp = temp->right;
  }
  return len;
}

Node *dllToBST(Node *&head, int n)
{
  if (!head || n <= 0)
    return NULL;

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

bool isBST(Node *root)
{
  if (!root)
  {
    return true;
  }

  if (root->left)
  {
    if (root->left->data > root->data)
    {
      return false;
    }
  }

  if (root->right)
  {
    if (root->right->data < root->data)
    {
      return false;
    }
  }

  return isBST(root->left) || isBST(root->right);
}

int main()
{
  // Create BST: 50 30 60 25 40 70 80 55 -1
  /*
      50
    /    \
   30    60
  / \    / \
25  40  55  70
              \
               80
  */
  Node *root = createBST();

  // Printing level order of BST with root
  cout << "Printing levelOrder: " << endl; // 50 , 30 60 , 25 40 55 70 , 80
  levelOrder(root);

  /*
    cout << "Printing preorder: "; // 50 30 25 40 60 55 70 80
    preorder(root);
    cout << endl;

    cout << "Printing inorder: "; // 25 30 40 50 55 60 70 80
    inorder(root);
    cout << endl;

    cout << "Printing postorder: "; // 25 40 30 55 80 70 60 50
    postorder(root);
    cout << endl;

    cout << "Find target: ";
    int target = 80;
    if (findTargetInBST(root, target))
    {
      cout << "Target found." << endl;
    }
    else
    {
      cout << "Target not found." << endl;
    }

    cout << "Find Minimum: " << findMinimum(root)->data << endl;
    cout << "Find Maximum: " << findMaximum(root)->data << endl;

  root = deleteNodeInBST(root, 55);
  cout << "Printing levelOrder: " << endl; // 50 , 30 60 , 25 40 70 , 80
  levelOrder(root);

  root = deleteNodeInBST(root, 70);
  cout << "Printing levelOrder: " << endl; // 50 , 30 60 , 25 40 80
  levelOrder(root);

  root = deleteNodeInBST(root, 50);
  cout << "Printing levelOrder: " << endl; // 40 , 30 60 , 25 80
  levelOrder(root);
*/

  /* CREATE BST using inorder traversal
  vector<int> inorder = {25, 30, 40, 50, 55, 60, 70, 80};
  int s = 0, e = inorder.size() - 1;
  Node *root1 = createBstUsingInorder(inorder, s, e);

  // Printing level order of BST with root1
  cout << "Printing levelOrder: " << endl; // 50 , 30 60 , 25 40 55 70 , 80
  levelOrder(root1);
   */

  /* BST to DLL */
  Node *head = NULL;
  bstToDLL(root, head);
  cout << "Printing DLL: ";
  printDLL(head);
  cout << endl;

  /* DLL to BST */
  Node *root2 = dllToBST(head, getDllLength(head));
  cout << "Printing levelOrder: " << endl; // 50 , 30 60 , 25 40 55 70 , 80
  levelOrder(root2);

  cout << "root2 is BST: " << (isBST(root2) ? "True" : "False") << endl;

  return 0;
}
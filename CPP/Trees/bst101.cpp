#include <iostream>
#include <climits>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
node *insertinBST(node *root, int d)
{
    // base case
    if (root == NULL)
    {
        root = new node(d);
        return root;
    }
    // recursive case
    if (d <= root->data)
    {
        root->left = insertinBST(root->left, d);
    }
    else
    {
        root->right = insertinBST(root->right, d);
    }
    return root;
}
node *createBST()
{
    node *root = NULL;
    int d;
    cin >> d;
    while (d != -1)
    {
        root = insertinBST(root, d);
        cin >> d;
    }
    return root;
}
void preorde(node *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << " ";
    preorde(root->left);
    preorde(root->right);
}
void inorder(node *root)
{
    if (!root)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void levelordertraveesal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *n = q.front();
        q.pop();
        if (n == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << n->data << " ";
            if (n->left)
            {
                q.push(n->left);
            }
            if (n->right)
            {
                q.push(n->right);
            }
        }
    }
}
node *searchBST(node *root, int key)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }
    // recursive case
    if (root->data == key)
    {
        return root;
    }
    else if (root->data > key)
    {
        return searchBST(root->left, key);
    }
    else
    {
        return searchBST(root->right, key);
    }
}
void printingBSTinrange(node *root, int k1, int k2)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    // if(root->data>k2 ||root->data<k1){
    //  return;
    //  }

    // recursive case
    if (k1 < root->data)
    {
        printingBSTinrange(root->left, k1, k2);
    }
    if (root->data >= k1 && root->data <= k2)
    {
        cout << root->data << " ";
    }
    if (k2 > root->data)
    {
        printingBSTinrange(root->right, k1, k2);
    }
}
int heightBT(node *root)
{
    if (!root)
    {
        return 0;
    }
    return max(heightBT(root->left), heightBT(root->right)) + 1;
}
bool isbalanced(node *root)
{
    // base case
    if (root == NULL)
    {
        return true;
    }
    // recursive case
    int left_height = heightBT(root->left);
    int right_height = heightBT(root->right);
    int curr_diff = abs(left_height - right_height);
    if (curr_diff <= 1 and isbalanced(root->left) and isbalanced(root->right))
    {
        return true;
    }
    else
    {
        return false;
    }
}
class Pair
{
public:
    int height;
    bool balanced;
};
Pair fastbalance(node *root)
{
    Pair p;
    // base case
    if (root == NULL)
    {
        p.height = 0;
        p.balanced = true;
        return p;
    }
    // recursive case
    Pair left = fastbalance(root->left);
    Pair right = fastbalance(root->right);
    p.height = max(left.height, right.height) + 1;
    if (abs(left.height - right.height) <= 1 and left.balanced and right.balanced)
    {
        p.balanced = true;
    }
    else
    {
        p.balanced = false;
    }
    return p;
}
bool isBST(node *root, int mi = INT_MIN, int mx = INT_MAX)
{
    // base case
    if (!root)
    {
        return true;
    }
    // recursive case
    if (root->data >= mi and root->data <= mx and isBST(root->left, mi, root->data) and isBST(root->right, root->data, mx))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    node *root = NULL;
    root = createBST();
    insertinBST(root, 9);
    cout << "pre:";
    preorde(root);
    cout << endl;
    cout << "inorder: ";
    inorder(root);
    cout << endl;
    cout << "level order:" << endl;
    levelordertraveesal(root);
    cout << endl;
    node *ans = searchBST(root, 14);
    if (ans)
    {
        cout << "key found:" << ans->data << endl;
    }
    else
    {
        cout << "key not found\n";
    }
    printingBSTinrange(root, 3, 10);
    cout << endl;
    bool balanced = isbalanced(root);
    if (balanced)
    {
        cout << "tree is balanced" << endl;
    }
    else
    {
        cout << "tree is not balanced\n";
    }
    Pair sol = fastbalance(root);
    if (sol.balanced)
    {
        cout << "tree is balanced\n";
    }
    else
    {
        cout << "not balanced" << endl;
    }
    cout << "fast height:" << sol.height << endl;
    if (isBST(root))
    {
        cout << "this is a BST";
    }
    else
    {
        cout << "this is not a bst";
    }
    return 0;
}
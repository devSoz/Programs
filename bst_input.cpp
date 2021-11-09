#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *create(int item)
{
    Node *node = new Node;
    node->data = item;
    node->left = node->right = NULL;
    return node;
}

void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << "   ";
    inorder(root->right);
}

Node *insertion(Node *root, int item)
{
    if (root == NULL)
        return create(item);
    if (item < root->data)
        root->left = insertion(root->left, item);
    else
        root->right = insertion(root->right, item);

    return root;
}

int main()
{
    Node *root = NULL;
    int n;
    cout << "Enter number of values to be inserted: ";
    cin >> n;
    int keys[n];
    cout << "Enter the values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> keys[i];
    }

    for (int i = 0; i < n; i++)
    {
        root = insertion(root, keys[i]);
    }
    cout << endl
         << "Inorder traversal: ";
    inorder(root);

    return 0;
}

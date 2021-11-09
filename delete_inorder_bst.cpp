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

Node *minVal(Node *cur)
{
    while (cur->left != NULL)
    {
        cur = cur->left;
    }
    return cur;
}

Node *deleteNode(Node *root, int data)
{
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);

    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    else
    {
        if (root->left == NULL and root->right == NULL)
            return NULL;

        else if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        else
        {
            struct Node *temp = minVal(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
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
    cout << "\n";
    int x = 1;
    cout << "Enter the value to be deleted (-1 to exit): ";
    cin >> x;
    while (x != -1)
    {
        deleteNode(root, x);
        cout << endl
             << "Inorder traversal: ";
        inorder(root);
        cout << "\n";
        cout << "Enter the value to be deleted (-1 to exit): ";
        cin >> x;
    }
    return 0;
}

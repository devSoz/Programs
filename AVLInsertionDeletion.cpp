#include <iostream>

using namespace std;

struct AVLNode
{
    int data;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
};

AVLNode *createNode(int x)
{
    AVLNode *temp = (struct AVLNode *)malloc(sizeof(struct AVLNode));
    temp->data = x;
    temp->right = NULL;
    temp->left = NULL;
    temp->height = 1;
    return (temp);
}

int height(AVLNode *k)
{
    if (k == NULL)
        return 0;
    return k->height;
    //return max(height(k->left), height(k->right))+1;
}

AVLNode *rotateRight(AVLNode *k)
{
    AVLNode *left = k->left;
    AVLNode *shift = left->right;

    left->right = k;
    k->left = shift;

    k->height = max(height(k->left), height(k->right)) + 1;
    left->height = max(height(left->left), height(left->right)) + 1;
    return left;
}

AVLNode *rotateLeft(AVLNode *k)
{
    AVLNode *right = k->right;
    AVLNode *shift = right->left;

    right->left = k;
    k->right = shift;

    k->height = std::max(height(k->left), height(k->right)) + 1;
    right->height = std::max(height(right->left), height(right->right)) + 1;
    return right;
}

int checkBalance(AVLNode *k)
{
    if (k == NULL)
        return 0;
    return height(k->left) - height(k->right);
}

AVLNode *minimumValue(AVLNode *k)
{
    while (k->left != NULL)
    {
        k = k->left;
    }
    return k;
}

AVLNode *deleteNode(AVLNode *root, int data)
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
            struct AVLNode *x = root->right;
            free(root);
            return x;
        }
        else if (root->right == NULL)
        {
            struct AVLNode *x = root->left;
            free(root);
            return x;
        }

        else
        {
            struct AVLNode *x = minimumValue(root->right);
            root->data = x->data;
            root->right = deleteNode(root->right, x->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = checkBalance(root);

    if (balance > 1 && checkBalance(root->left) >= 0)
        return rotateRight(root);

    if (balance > 1 && checkBalance(root->left) < 0)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && checkBalance(root->right) <= 0)
        return rotateLeft(root);

    // Right Left Case
    if (balance < -1 && checkBalance(root->right) > 0)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

AVLNode *insertNode(AVLNode *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
        return root;
    }

    if (root->data > data)
        root->left = insertNode(root->left, data);
    else if (root->data < data)
        root->right = insertNode(root->right, data);
    else
        return root;

    //cout<<root->data<<" ";
    int balanceTemp = checkBalance(root);
    root->height = std::max(height(root->left), height(root->right)) + 1;

    if (balanceTemp >= 2)
    {
        if (root->left->data > data)
            return rotateRight(root);
        else
        {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }

    else if (balanceTemp <= -2)
    {
        if (root->right->data > data)
        {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
        else
            return rotateLeft(root);
    }
    return root;
}

void inOrder(AVLNode *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(AVLNode *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(AVLNode *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    AVLNode *root = NULL;
    int n, x;
    cout << "Number of values to be inserted: ";
    cin >> n;
    int keys[n];
    cout << "Enter the values: ";
    for (int i = 0; i < n; i++)
        cin >> keys[i];

    for (int i = 0; i < n; i++)
    {
        root = insertNode(root, keys[i]);
    }

    cout << "Inorder traversal (AVL Tree): ";
    inOrder(root);
    cout << "\nPreorder traversal (AVL Tree): ";
    preOrder(root);
    cout << "\nPostorder traversal (AVL Tree): ";
    postOrder(root);

    int c = 1;
    while (c != -1)
    {
        cout << "\n\nEnter data to be deleted: ";
        cin >> x;
        deleteNode(root, x);

        cout << "Inorder traversal (after deletion): ";
        inOrder(root);
        cout << "\nPreorder traversal (after deletion): ";
        preOrder(root);
        cout << "\nPostorder traversal (after deletion): ";
        postOrder(root);
        cout << "\n\nDo you want to continue? (Y: 1, N: -1)";
        cin >> c;
    }
}
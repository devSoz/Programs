#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

int count(struct Node *root)
{
    if (root == NULL)
        return (0);
    return (1 + count(root->left) + count(root->right));
}

bool isCompleteBinTree(struct Node *root, int i, int n)
{
    if (root == NULL)
        return true;
    if (i >= n)
        return false;

    return ((isCompleteBinTree(root->left, 2 * i + 1, n)) && (isCompleteBinTree(root->right, 2 * i + 2, n)));
}

struct Node *input()
{
    struct Node *temp;
    int x;
    printf("Enter data(enter -1 for null): ");
    scanf(" %d", &x);

    if (x == -1)
        return NULL;

    temp = malloc(sizeof(struct Node));
    temp->data = x;

    printf("Left child of %d: \n", x);
    temp->left = input();

    printf("Right child of %d: \n", x);
    temp->right = input();
    return temp;
}

int main()
{
    struct Node *root;
    root = malloc(sizeof(struct Node));

    root = input();
    int n = count(root);
    bool x = isCompleteBinTree(root, 0, n);
    if (x)
        printf("It's a complete binary tree");
    else
        printf("It's not a complete binary tree");
    return 0;
}

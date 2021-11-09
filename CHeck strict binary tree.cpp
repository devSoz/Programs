#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

bool isStrictBinTree(struct Node *root)
{
    if (root == NULL)
        return true;

    if (((root->right == NULL) && (root->left != NULL)) || ((root->right != NULL) && (root->left == NULL)))
    {
        return false;
    }

    return (isStrictBinTree(root->left) && isStrictBinTree(root->right));
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
    bool x = isStrictBinTree(root);
    if (x)
        printf("It's a strict binary tree");
    else
        printf("It's not a strict binary tree");
    return 0;
}

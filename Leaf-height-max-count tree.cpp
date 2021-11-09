#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

int sumNodes(struct Node *root)
{
    if (root == NULL)
        return 0;
    return (root->data + sumNodes(root->left) + sumNodes(root->right));
}

int height(struct Node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int lheight = height(root->left);
        int rheight = height(root->right);

        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

int maxElement(struct Node *root)
{
    if (root == NULL)
        return -999999;
    int max = root->data;
    int left = maxElement(root->left);
    int right = maxElement(root->right);
    if (left > max)
        max = left;
    if (right > max)
        max = right;
    return max;
}

int countLeaf(struct Node *root)
{
    if (root == NULL)
        return 0;
    if ((root->right == NULL) && (root->left == NULL))
    {
        return 1;
    }
    return countLeaf(root->left) + countLeaf(root->right);
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

    printf("Count of leaf : %d", countLeaf(root));
    printf("\nMaximum element : %d", maxElement(root));
    printf("\nHeight of Tree : %d", height(root));
    printf("\nSum of elements : %d", sumNodes(root));
    return 0;
}

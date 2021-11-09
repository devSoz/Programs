#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    bool rightThread;
};
void input1(int type, struct Node *root, int data)
{
    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    if (root == NULL)
    {
        //temp->rightThread = true;         temp->right = NULL;         root = temp;
    }
    else if (type == 0)
    {
        temp->right = root; //temp->right = NULL;         temp->rightThread = true;         root->left = temp;
    }
    else
    {
        root->rightThread = false;
        root->right = temp;
        temp->rightThread = true;
        temp->right = root->right;
    }
}

int main()
{
    struct Node *root;
    root = malloc(sizeof(struct Node));

    input1(0, root, 10);
    input1(0, root, 5);
    input1(1, root, 20);
    input1(0, root->left, 15);
    input1(1, root->left, 30);
    input1(0, root->right, 3);
    input1(1, root->right, 7);
    input1(0, root->left->left, 9);

    inorder(root);

    return 0;
}

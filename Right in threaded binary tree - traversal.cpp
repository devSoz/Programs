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

void inorder(struct Node *root)
{
    if (root == NULL)
        return;

    while (true)
    {
        if (root->left != NULL)
        {
            root = root->left;
        }
        else
        {
            printf("%d ", root->data);

            if (!root->left && !root->right)
                return;

            if (root->right)
            {
                do
                {
                    root = root->right;
                    printf("%d ", root->data);
                } while (root->rightThread);
                root = root->right;
            }
        }
    }
}
struct Node *newnode(int data)
{
    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->rightThread = NULL;
    return temp;
}

void preorder(struct Node *root)
{

    struct Node *curr = root;
    int n = 1;
    while (curr != NULL && n <= 7)
    {
        n++;
        printf("%d ", curr->data);

        if (curr->left != NULL)
            curr = curr->left;

        else if (curr->rightThread)
            curr = curr->right;
        else
        {
            while (curr->right != NULL && !curr->rightThread)
                curr = curr->right;

            if (curr->right == NULL)
                break;
            else
                curr = curr->right;
        }
    }
}

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
        temp->right = root; //temp->right = NULL;         temp->rightThread = true;
        root->left = temp;
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
    struct Node *temp; /* input1(0, root,10);     input1(0, root, 5);     input1(1, root, 20);     input1(0, root->left, 15);     input1(1, root->left, 30);     input1(0, root->right, 3);     input1(1, root->right, 7); 
    input1(0, root->left->left, 9);*/

    root = newnode(10);
    temp = newnode(5);
    root->left = temp;
    temp = newnode(20);
    root->right = temp;
    temp = newnode(15);
    root->left->left = temp;

    temp = newnode(30);
    root->left->right = temp;
    temp = newnode(3);
    root->right->left = temp;
    temp = newnode(7);
    root->right->right = temp;
    temp = newnode(9);
    root->left->left->left = temp;
    root->left->left->left->right = root->left->left;
    root->left->left->left->rightThread = true;

    root->left->left->right = root->left;
    root->left->left->rightThread = true;

    root->left->right->right = root;
    root->left->right->rightThread = true;

    root->right->left->right = root->right;
    root->right->left->rightThread = true;
    printf("\n Inorder traversal :");
    inorder(root);
    printf("\n Preorder traversal :");
    preorder(root);
    return 0;
}

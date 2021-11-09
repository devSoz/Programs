#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;
};

struct Stack
{
    int top;
    unsigned max;
    Node *array;
};

struct Stack *createStack(unsigned max)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->max = max;
    stack->top = -1;
    stack->array = (Node *)malloc(stack->max * sizeof(Node));
    return stack;
}

int isFull(struct Stack *stack)
{
    return stack->top == stack->max - 1;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, Node *node)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = *node;
}

Node *pop(struct Stack *stack)
{
    Node *temp = stack->array[stack->top--];
    return temp;
}

Node *create(char item)
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

Node *createExpTree(Node *root, string exp)
{
    if (root == NULL)
        return root;
    struct Stack *stack = createStack(exp.length());
    for (int i = 0; i < exp.length(); i++)
    {
        if (isalpha(exp[i]) || isdigit(exp[i]))
        {
            Node *temp = create(exp[i]);
            push(stack, temp);
        }
        else
        {
            Node *left = pop(stack);
            Node *right = pop(stack);
            Node *temp = create(exp[i]);
            temp->left = left;
            temp->right = right;
            push(stack, temp);
        }
    }

    return pop(stack);
}

int main()
{
    Node *root = NULL;

    string expr;

    cout << "Enter the expression: ";
    cin >> expr;

    root = createExpTree(root, expr);

    inorder(root);
    return 0;
}

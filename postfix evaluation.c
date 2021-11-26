#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100
enum op
{
    others,
    plusMinus,
    productDiv,
    expo
};
struct Stack
{
    int stackTop;
    char arr[100];
};
int value(char c)
{
    if (c == '^')
        return expo;
    else if ((c == '*') || (c == '/'))
        return productDiv;
    else if ((c == '+') || (c == '-'))
        return plusMinus;
    else
        return others;
}
bool isFull(struct Stack *stackObj)
{
    return stackObj->stackTop == (SIZE - 1);
}
bool isEmpty(struct Stack *stackObj)
{
    return stackObj->stackTop == (-1);
}
void push(struct Stack *stackObj, char data)
{
    if (isFull(stackObj))
    {
        printf("Stack is full!");
        return;
    }
    stackObj->stackTop++;
    stackObj->arr[stackObj->stackTop] = data;
}
char stackTopShow(struct Stack *stackObj)
{
    return stackObj->arr[stackObj->stackTop];
}
void print(struct Stack *stackObj)
{
    printf("The elements of the stack are: ");
    for (int i = 0; i < (stackObj->stackTop); i++)
    {
        printf(" %c ", stackObj->arr[i]);
    }
}
void pop(struct Stack *stackObj)
{
    if (isEmpty(stackObj))
    {
        printf("Stack is empty");
        return;
    }
    //printf("Element %d is popped", stackObj->arr[stackObj->stackTop]);
    stackObj->stackTop--;
}
void evaluate(char postfix[])
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    for (int i = 0; i < strlen(postfix); i++)
    {
        // printf("%c,",postfix[i]);
        if (isdigit(postfix[i]))
        {
            push(s, postfix[i] - '0');
            // printf("push,");
        }

        else
        {

            int x = stackTopShow(s);
            pop(s);
            int y = stackTopShow(s);
            pop(s);
            printf("%d,%d,%c", x, y, postfix[i]);
            if (postfix[i] == '+')
                push(s, x + y);
            else if (postfix[i] == '-')
                push(s, x - y);
            else if (postfix[i] == '*')
                push(s, x * y);
            else if (postfix[i] == '/')
                push(s, y / x);
        }
    }

    printf("Evaluated value of the expression: %d", stackTopShow(s));
}
int main()
{
    char infix[100];
    printf("Enter the postfix expression: ");
    scanf("%s", infix);
    evaluate(infix);
}
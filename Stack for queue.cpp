
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 10



struct Stack
{
 int stackTop;
 int arr[100];
}s1,s2;

void enqueue (int);
void dequeue ();
bool isFull (struct Stack*) ;
bool isEmpty (struct Stack*);
void push (struct Stack*,int) ;
void pop (struct Stack*) ;
int peek (struct Stack*) ;
void display(struct Stack*);
int size;

////Stack ADT members

bool isFull(struct Stack *stackObj)
{
    return stackObj->stackTop==(SIZE-1);
}

bool isEmpty(struct Stack *stackObj)
{
    return stackObj->stackTop==(-1);
}

void push(struct Stack *stackObj,int data)
{
     if(isFull(stackObj))
     {
         printf("Stack is full!");
         return;
     }
     stackObj->stackTop++;

     stackObj->arr[stackObj->stackTop] = data;
}

void pop(struct Stack *stackObj)
{
     if(isEmpty(stackObj)!=-1)
     {
        stackObj->stackTop--;
     }
}

int peek(struct Stack *stackObj)
{
    if(isEmpty(stackObj))
         return -1;
    else
        return stackObj->arr[stackObj->stackTop];
}

void display(struct Stack *stackObj)
{
     printf("\nThe elements of the stack are: ");
     for(int i=0; i<=(stackObj->stackTop); i++)
     {
        printf(" %d ", stackObj->arr[i]);
     }
}


     
void enqueue(int x)
{
    if(isFull(&s1))
         printf("Queue is full");
    else
    {
        while(!isEmpty(&s1))
    	{
    	   // printf("insidde");
    		int temp = peek(&s1);
    		push(&s2,temp);
    		pop(&s1);
    	}
    
        push(&s1,x);
    	
    	while(!isEmpty(&s2))
    	{
    		int temp =  peek(&s2);
    		push(&s1,temp);
    		pop(&s2);
    	}
    	
    	printf("%d is inserted\n", x);
    //	printf("\n...%d...\n", s1.stackTop);
    }
  
}

void dequeue()
{
    int element = peek(&s1);
    if(element==-1)
        printf("Queue is empty");
    else
    {
        pop(&s1);
        printf("\n%d is deleted\n", element);
    }
}


void main(void)
{
    int ch,x;
    s1.stackTop = -1; s2.stackTop = -1;
    
   
    do
    {
        printf("\n1.Enqueue  2.Dequeue  3.display  4.exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter the element: ");
                scanf("%d",&x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display(&s1);
                break;
            case 4:
                exit(0);
            default:
                printf("\n Invalid choice");
        }
    }while(ch<=4);

}

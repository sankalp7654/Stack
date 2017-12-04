#include<stdio.h>
#define SIZE 69
#include<stdlib.h>

int stackempty(int top)
{
  if(top == -1)
    return 1;
  return 0;
}

int stackfull(int top)
{
  if(top == SIZE-1)
    return 1;
  return 0;
}

void push(int item, int *top, int stack[])
{
  stack[++(*top)] = item;
}

void pop(int *top, int stack[])
{
  printf("The popped element is %d\n", stack[(*top)--]);
}

void display(int top, int stack[])
{
  int i;
  for(i=top ; i>=0 ; i--)
    printf("%d \n", stack[i]);
}

void palindrome(int stack[], int top)
{
  int i, flag = 0;
  for(i=0 ; i<(top/2) ; i++)
  {
    if(stack[i] == stack[top-i])
    flag++;
  }
  if(flag == (top/2))
    printf("Stack is PALINDROME\n");
  else
    printf("Stack is not PALINDROME\n" );
}

void main()
{
  int stack[SIZE], top=-1, ch, item;
  for( ; ; )
  {
    printf("1 PUSH \n2 POP \n3 DISPLAY \n4 PALINDROME \n5 EXIT \n" );
    scanf("%d",&ch );
    switch(ch)
    {
      case 1 : if(stackfull(top))
                  printf("Stack is full\n" );
               else
               {
                 printf("Enter the item\n" );
                 scanf("%d", &item );
                 push(item, &top, stack);
               }
               break;

      case 2 : if(stackempty(top))
                  printf("Stack is empty\n");
               else
               {
                 pop(&top, stack);
               }
               break;

      case 3 : if(stackempty(top))
                  printf("Stack is empty\n");
               else
               {
                 printf("The stack is \n");
                 display(top, stack);
               }
               break;

      case 4 : palindrome(stack, top);
               break;

      case 5 : exit(0);
    }
  }
}

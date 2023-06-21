#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
int stack[5];
int top=-1;
void push()
{
    int x;
    printf("Enter the data:");
    scanf("%d",&x);
    if(top==4)
    {
        printf("OVERFLOW\n");
    }
    else
    {
        top=top+1;
        stack[top]=x;
    }
}
void pop()
{
    int x;
    if(top==-1)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        x=stack[top];
        top=top-1;
        printf("Item popped is:%d\n",x);
    }
}
void peek()
{
    if(top==-1)
    {
        printf("Stack is Empty!\n");
    }
    else
    {
        printf("Element at top is %d\n",stack[top]);
    }
}
void display()
{
    int i;
    for(i=0;i<=top;i++)
    {
        printf("%d\n",stack[i]);
    }
}
void main()
{
    int ch;
    do
    {
        printf("Enter choice:\n1.PUSH()\n2.POP()\n3.PEEK()\n4.DISPLAY()\n");
        scanf("%d",&ch);
            
        
        switch(ch)
        {
            case 1:push();
                break;
            case 2:pop();
                break;
            case 3:peek();
                break;
            case 4:display();
                break;
            default:
                printf("INVALID CHOICE\n");
        }
    }
    while(ch!=0);
}

#include<stdio.h>
#include<malloc.h>
struct node *top=NULL;
struct node *push();
struct node *pop();
struct node *peek();
struct node *display();
struct node{
    int data;
    struct node *link;
};
struct node *push()
{
    int x;
    struct node *temp=NULL;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data to be pushed");
    scanf("%d",&x);
    newnode->data=x;
    newnode->link=top;
    top=newnode;
}
struct node *pop()
{
    struct node *temp;
    if(top==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        temp=top;
        top=top->link;
        printf("%d Popped\n",temp->data);
        free(temp);
    }
}
struct node *peek()
{
    if(top==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("%d\n",top->data);
    }
}
struct node *display()
{
    struct node *temp;
    if(top==NULL) 
    {
        printf("Stack is empty");
    }
    else
    {
        temp=top;
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->link;
        }
    }
}
void main()
{
    int ch;
    do
    {
        printf("Enter the choice:\n1.Push()\n2.Pop()\n3.Peek()\n4.Display()\n");
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
            printf("Invalid Choice");
        }
    }
    while(ch!=0);
}
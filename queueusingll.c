#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<conio.h>
int main()
{
    int ch;
    do
    {
        printf("Enter the choice");
        printf("1. To enqueue");
        printf("2. To dequeue");
        printf("3. To display");
        printf("4. To peek");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:enqueue();
            break;
            case 2:dequeue();
            break;
            case 3:display();
            break;
            case 4:peek();
            break;
        }
    } while (ch!=4);
    getch();
}
struct node *enqueue();
struct node *dequeue();
struct node *display();
struct node *peek();
struct node *head=NULL;
struct node *tail=NULL;

struct node enqueue()
{
    int x;
    printf("Enter the data");
    scanf("%d",&x);
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=tail=newnode;

    }
    else
    {
        newnode=tail->next;
        tail=tail->next;
    }
}

struct node *dequeue()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("Queue is empty");

    }
    else
    {
        head=head->next;
        free(temp);
    }
}
struct node *display()
{
    struct node *temp=head;
    while(temp->next!=NULL)
    {
        printf("%d",temp->data);
    }
}
struct node *peek()
{
    if(head==NULL)
    {
        printf("Queue is empty");

    }
    else
    {
        printf("%d",head->data);
    }
}
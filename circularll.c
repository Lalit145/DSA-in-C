#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
}
struct node *createll;
struct node *insert;
struct node *delete;
struct node *createll();
{
    int n;
    printf("Enter data:");
    scanf("%d",&n);
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->next=NULL;
        
}
struct node *insert()
{
    if(start==NULL)
    {
        start=newnode;
        ptr=newnode;
    }
    else
    {
        ptr->next=newnode;
    }
}
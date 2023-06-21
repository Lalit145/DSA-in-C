#include<stdio.h>;
#include<stdlib.h>;
#include<conio.h>;
struct node {
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node *create(struct node *);
struct node *insert(struct node *);
struct node *insertatbeg(struct node *);
struct node *insertatend(struct node *);
struct node *deletebeg(struct node *);
struct node *deleteend(struct node *);
struct node *display(struct node *);
int main()
{
    int option;
    do{
            printf("MAIN MENU");
            printf("Enter 1 to create a list");
            printf("Enter 2 to insert node");
            printf("Enter 3 to insert at beginning");
            printf("Enter 4 to insert at end");
            printf("Enter 5 to delete from beginning");
            printf("Enter 6 to delete from end");
            printf("Enter your choice:")
            scanf("%d",&option);
            switch (option)
            {
            case 1:start=create(start);
                printf("LINKED LIST CREATED!");
                break;
            case 2:start=insert(start);
                break;
            case 3:start=insertatbeg(start);
                break;
            case 4:start=insertatend(start);
                break;
            case 5:start=deletebeg(start);
                break;
            case 6:start=deleteend(start);
                break;
            
            default:
                break;
            }
        }
            while(option!=6)
            {
                getch();
                return 0;
            }
    }
    struct node *create(struct node *start);
    {
        struct node *newnode,ptr;
        int num;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data");
        printf("Enter -1 to end");
        scanf("%d",&num);
        while(num!=-1)
        {
            
        }
    }

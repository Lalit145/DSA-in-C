#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node *createll(struct node *);
struct node *display(struct node *);
struct node *insertbeg(struct node *);
struct node *insertend(struct node *);
struct node *insertbefore(struct node *);
struct node *insertafter(struct node *);
struct node *deletebeg(struct node *);
struct node *deleteend(struct node *);
struct node *deletenode(struct node *);
struct node *deleteafter(struct node *);
struct node *deletelist(struct node *);
struct node *sortlist(struct node *);
struct node *reversell(struct node *);
int main()
{
    int option;
    do
    {
        printf("\n****MAIN MENU****");
        printf("\n 1.Create a list\n");
        printf("\n 2.Display the list\n");
        printf("\n 3.Add a node at the beginning\n");
        printf("\n 4.Add a node at the end\n");
        printf("\n 5.Add a node after another node\n");
        printf("\n 6.Add a node before another node\n");
        printf("\n 7.Delete a node at the beginning\n");
        printf("\n 8.Delete a node at the end\n");
        printf("\n 9.Delete a given node\n");
        printf("\n 10.Delete a node after a given node\n");
        printf("\n 11.Delete entire list\n");
        printf("\n 12.Sort the list\n");
        printf("\n 13.EXIT\n");
        printf("\n ENTER YOUR CHOICE:");
        scanf("%d",&option);
        switch(option)
        {
            case 1:start=createll(start);
                    printf("LINKED LIST CREATED!");
                    break;
            case 2:start=display(start);
                    break;
            case 3:start=insertbeg(start);
                    break;
            case 4:start=insertend(start);
                    break;
            case 5:start=insertbefore(start);
                    break;
            case 6:start=insertafter(start);
                    break;
            case 7:start=deletebeg(start);
                    break;
            case 8:start=deleteend(start);
                    break;
            case 9:start=deletenode(start);
                    break;
            case 10:start=deleteafter(start);
                    break;
            case 11:start=deletelist(start);
                    printf("LINKED LIST DELETED\n");
                    break;
            case 12:start=sortlist(start);
                    break;
            case 13:start=reversell(start);
                    break;
    }
        }while(option!=13);
        getch();
        return 0;
}
struct node *createll(struct node *start)
{
    struct node *newnode,*ptr;
    int num;
    printf("Enter -1 to end\n");
    printf("Enter the data:");
    scanf("%d",&num);
    while(num!=0)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=num;
        if(start==NULL)
        {
            newnode->next=NULL;
            start=newnode;
        }
        else
        {
            ptr=start;
            while(ptr->next=NULL)
            {
                ptr=ptr->next;
                ptr->next=newnode;
                newnode->next=NULL;
            }
        }
            printf("Enter the data:");
            scanf("%d",&num);
    }
        return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
    return start;
}
struct node *insertbeg(struct node *start)
{
    struct node *newnode;
    int num;
    printf("Enter the data:");
    scanf("%d",&num);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=start;
    start=newnode;
    return start;
}
struct node *insertend(struct node *start)
{
    struct node *ptr,*newnode;
    int num;
    printf("\n Enter the data:");
    scanf("%d",&num);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=NULL;
    ptr=start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
        ptr->next=newnode;
    }
    return start;
}
struct node *insertbefore(struct node *start)
{
    struct node *newnode,*ptr,*preptr;
    int num,val;
    printf("\n Enter the data:");
    scanf("%d",&num);
    printf("\n Enter the value before which you want to insert:");
    scanf("%d",&val);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    ptr=start;
    while(ptr->data!=val)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=newnode;
    newnode->next=ptr;
    return start;
}
struct node *insertafter(struct node *start)
{
    struct node *newnode,*ptr,*preptr;
    int num,val;
    printf("\n Enter the data:");
    scanf("%d",&num);
    printf("\n Enter the value after which the data has to be inserted");
    scanf("%d",&val);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    ptr=start;
    preptr=ptr;
    while(preptr->data!=val)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=newnode;
    newnode->next=ptr;
    return start;

}
struct node *deletebeg(struct node *start)
{
    struct node *ptr;
    ptr=start;
    start=start->next;
    free(ptr);
    return start;
}
struct node *deleteend(struct node *start)
{
    struct node *ptr,*preptr;
    ptr=start;
    while(ptr->next!=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=NULL;
    free(ptr);
    return start;
}
struct node *deletenode(struct node *start)
{
    struct node *ptr,*preptr;
    int val;
    printf("\n Enter the value of the node yo want delete:");
    scanf("%d",&val);
    ptr=start;
    if(ptr->data=val)
    {
        start=deletebeg(start);
        return start;
    }
    else
    {
        while(ptr->data!=val)
        {
            preptr=ptr;
            ptr=ptr->next;

        }
        preptr->next=ptr->next;
        free(ptr);
        return start;
    }
}
struct node *deleteafter(struct node *start)
{
    struct node *ptr,*preptr;
    int val;
    printf("\n Enter the value after which the node has to deleted:");
    scanf("%d",&val);
    ptr=start;
    preptr=ptr;
    while(preptr->data!=val)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=ptr->next;
    free(ptr);
    return start;
}
struct node *deletelist(struct node *start)
{
    struct node *ptr;
    if(start!=NULL)
    {
        ptr=start;
        while(ptr!=NULL)
        {
            printf("\n %d is to be deleted next",ptr->data);
            start=deletebeg(ptr);
            ptr=start;
        }
    }
    return start;
}
struct node *sortlist(struct node *start)
{
    struct node *ptr1,*ptr2;
    int temp;
    ptr1=start;
    while(ptr1->next!=NULL)
    {
        ptr2=ptr1->next;
        while(ptr2!=NULL)
        {
            if(ptr1->data>ptr2->data)
            {
                temp=ptr1->data;
                ptr1->data=ptr2->data;
                ptr2->data=temp;

            }
            ptr2=ptr2->next;

        }
        ptr1=ptr1->next;
    }
    return start;
}
struct node *reversell(struct node *start)
{
   createll(start);
   while(start->next!=NULL)
   {
    insertbeg(start);
   } 
   return start;
}
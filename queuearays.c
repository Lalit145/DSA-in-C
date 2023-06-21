#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;
 void enqueue()
 {
    int x;
    printf("Enter the number to enqueue:");
    scanf("%d",&x);
    if(front==-1&&rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else
    {
        rear=rear+1;
        queue[rear]=x;
    }
 }
 void dequeue()
 {
    if(front==-1&&rear==-1)
    {
        printf("Queue is empty");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front=front+1;

    }
 }
 void display()
 {
    int i;
    if(front==rear==-1)
    {
        printf("Queue is empty");
    }
    else
    {
    for(i=front;i<=rear;i++)
    {
        printf("%d|",queue[i]);
    }
    }
 }
 void peek()
 {
    if(front==rear==-1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("%d\n",queue[front]);
    }
 }
 int main()
 {
    int ch;
    do
    {
        printf("Main Menu\n");
        printf("Press 1 to enqueue\n");
        printf("Press 2 to dequeue\n");
        printf("Press 3 to peek front element\n");
        printf("Press 4 to display\n");
        printf("Press 5 to exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:enqueue();
            break;
        case 2:dequeue();
            break;
        case 3:peek();
            break;
        case 4:display();
            break;
        
        default:
            break;
        }
    } while (ch!=5);
    getch();

 }
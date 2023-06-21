#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node* createnode(int data)
{
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
//Preorder traversal(root->left->right)
void preorder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
//Postorder traversal(left->right->root)
void postorder(struct node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
//Inorder traversal(left->root->right)
void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int main()
{
    // Replacing allocation multiple times by using function
    // p=(struct node *)malloc(sizeof(struct node));
    // struct node *p1;
    // p1=(struct node *)malloc(sizeof(struct node));
    // struct node *p2;
    // p2=(struct node *)malloc(sizeof(struct node));

    // p->data=2;
    // p->left=NULL;
    // p->right=NULL;

    // p1->data=1;
    // p1->left=NULL;
    // p1->right=NULL;

    // p2->data=4;
    // p2->left=NULL;
    // p2->right=NULL;

    struct node *p=createnode(7);
    struct node *p1=createnode(2);
    struct node *p2=createnode(0);
    struct node *p3=createnode(4);
    struct node *p4=createnode(1);
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    inorder(p);
    return 0;
}
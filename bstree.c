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
// void preorder(struct node* root)
// {
//     if(root!=NULL)
//     {
//         printf("%d ",root->data);
//         preorder(root->left);
//         preorder(root->right);
//     }
// }
// //Postorder traversal(left->right->root)
// void postorder(struct node* root)
// {
//     if(root!=NULL)
//     {
//         postorder(root->left);
//         postorder(root->right);
//         printf("%d ",root->data);
//     }
// }
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
int isBST(struct node *root)
{
    if(root!=NULL)
    {
        struct node *prev=NULL;
        if(!isBST(root->left))
        {
         return 0;
        }
        if(prev!=NULL && root->data<=prev->data)
        {
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else
    {
            return 1;
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

    struct node *p=createnode(5);
    struct node *p1=createnode(3);
    struct node *p2=createnode(6);
    struct node *p3=createnode(1);
    struct node *p4=createnode(4);
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    // preorder(p);
    // postorder(p);
    inorder(p);
    return 0;
}
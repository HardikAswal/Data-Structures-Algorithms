#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"

struct Node* root=NULL;

void TreeCreate()
{
    struct Node *p,*t;
    int x;
    struct Queue q;
    Create(&q,100);
    printf("Enter root value: \n");
    scanf("%d",&x);
    root=(struct Node *)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    Enqueue(&q,root);

    while(!isEmpty(q))
    {
        p=Dequeue(&q);

        printf("Enter left child of %d: ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            Enqueue(&q,t);
        }

        printf("Enter right child of %d: ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            Enqueue(&q,t);
        }
    }
}

void preorder(struct Node *p)
{
    if(p)
    {
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(struct Node *p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}

void postorder(struct Node *p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}

void IPreorder(struct Node *p)
{
    struct Stack stk;
    StackCreate(&stk,100);

    while(p || !isEmptyStack(stk))
    {
        if(p)
        {
            printf("%d ",p->data);
            push(&stk,p);
            p=p->lchild;
        }
        else
        {
            p=pop(&stk);
            p=p->rchild;
        }
    }
}

void IInorder(struct Node *p)
{
    struct Stack stk;
    StackCreate(&stk,100);

    while(p || !isEmptyStack(stk))
    {
        if(p)
        {
            push(&stk,p);
            p=p->lchild;
        }
        else
        {
            p=pop(&stk);
            printf("%d ",p->data);
            p=p->rchild;
        }
    }
}

void ILevelorder(struct Node *root)
{
    struct Queue q;
    Create(&q,100);
    printf("%d",root->data);
    Enqueue(&q,root);
    while(!isEmpty(q))
    {
        root=Dequeue(&q);
        if(root->lchild)
        {
            printf("%d ",root->lchild->data);
            Enqueue(&q,root->lchild);
        }
        if(root->rchild)
        {
            printf("%d ",root->rchild->data);
            Enqueue(&q,root->rchild);
        }
    }
}

int count(struct Node *root)
{
    if(root)
        return count(root->lchild)+count(root->rchild)+1;
    return 0;
}

int height(struct Node *root)
{
    int x=0,y=0;
    if(root==0)
        return 0;
    x=height(root->lchild);
    y=height(root->rchild);
    if(x>y)
        return x+1;
    else
        return y+1;
}

int main()
{
    TreeCreate();
    printf("Count: %d",count(root));
    printf("Height: %d",height(root));
    return 0;
}

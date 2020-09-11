#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void Create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    head=malloc(sizeof(struct Node));
    head->data=A[0];
    head->next=head;
    last=head;

    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

int Length(struct Node *h)
{
    int length=0;

    do
    {
        length++;
        h=h->next;
    }
    while(h!=head);
    return length;
}

void Insert(struct Node *h,int index, int x)
{
    struct Node *t;
    int i;

    if(index<0 || index>Length(h))
        return;

    if(index==0)
    {
       t=(struct Node *)malloc(sizeof(struct Node));
       t->data=x;

       if(head==NULL)
       {
           head=t;
           head->next=head;
       }
       else
       {
           while(h->next!=head)
                h=h->next;
           h->next=t;
           t->next=head;
           head=t;
       }
    }
    else
    {
        for(i=0;i<index-1;i++)
            h=h->next;
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->next=h->next;
        h->next=t;
    }
}

void Display(struct Node *h)
{
    do
    {
        printf("%d ",h->data);
        h=h->next;
    }
    while(h!=head);
    printf("\n");
}

void RDisplay(struct Node *h)
{
    static int flag=0;

    if(h!=head || flag==0)
    {
        flag=1;
        printf("%d ",h->data);
        RDisplay(h->next);
    }
    flag=0;
}

int Delete(struct Node *h, int index)
{
    struct Node *q;
    int i,x;

    if(index<0 || index>Length(h))
        return -1;

    if(index==1)
    {
        while(h->next!=head)
            h=h->next;
        x=head->data;
        if(head==h)
        {
            free(head);
            head=NULL;
        }
        else
        {
            h->next=head->next;
            free(head);
            head=h->next;
        }
    }
    else
    {
        for(i=0;i<index-2;i++)
            h=h->next;
        q=h->next;
        h->next=q->next;
        x=q->data;
        free(q);
    }
    return x;
}

int main()
{
    int A[]={2,3,4,5,6};
    Create(A,5);
    Delete(head,3);
    Display(head);
    return 0;
}

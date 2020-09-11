#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *front=NULL;
struct Node *rear=NULL;

void Enqueue(int x)
{
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));

    if(t==NULL)
        printf("Queue is Full.");
    else
    {
        t->data=x;
        t->next=NULL;
        if(front==NULL)
            front=rear=t;
        else
        {
            rear->next=t;
            rear=t;
        }
    }
}

int Dequeue()
{
    int x=-1;
    struct Node *p;

    if(front==NULL)
        printf("Queue is empty.\n");
    else
    {
        x=front->data;
        p=front;
        front=front->next;
        free(p);
    }
    return x;
}

void Display()
{
    struct Node *p=front;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main()
{
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);
    Enqueue(50);
    Display();
    printf("%d",Dequeue());
    return 0;
}

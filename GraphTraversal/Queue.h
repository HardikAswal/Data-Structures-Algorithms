#include<stdio.h>

struct Queue
{
    int data;
    struct Queue *next;
};

struct Queue *front=NULL;
struct Queue *rear=NULL;

void Enqueue(int x)
{
    struct Queue *t;
    t=(struct Queue *)malloc(sizeof(struct Queue));
    t->data=x;
    t->next=NULL;
    if(t==NULL)
        printf("Queue is full.\n");
    else
    {
        if(front==NULL)
        {
            front=rear=t;
        }
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
    struct Queue *t;
    if(rear==NULL)
        printf("Queue is empty.\n");
    else
    {
        t=front;
        front=front->next;
        x=t->data;
        free(t);
    }
return x;
}

int isEmpty()
{
    return front==NULL;
}



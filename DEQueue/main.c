#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void Create(struct Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=-1;
    q->Q=(struct Queue *)malloc(q->size*sizeof(struct Queue));
}

void enqueueRear(struct Queue *q,int x)
{
    if((q->rear+1)%q->size==q->front)
        printf("Queue is full.\n");
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

void enqueueFront(struct Queue *q,int x)
{
    if(q->front==NULL)
    {
        q->Q[q->front]=x;
        q->front=(q->front-1)%q->size;
    }
    else
        printf("No Space.");
}

int dequeueFront(struct Queue *q)
{
    int x=-1;
    if(q->front==q->rear)
        printf("Queue is Empty.\n");
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
        q->front=NULL;
    }
    return x;
}

int dequeueRear(struct Queue *q)
{
    int x=-1;
    if(q->rear!=q->front || q->rear!=-1)
    {
        x=q->Q[q->rear];
        q->rear--;
    }
    else
        printf("Queue is empty.\n");
    return x;
}

void Display(struct Queue q)
{
    int i;
    for(i=q.front+1;i<=q.rear;i++)
    {
        printf("%d ",q.Q[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue q;
    Create(&q,5);
    enqueueRear(&q,10);
    enqueueRear(&q,20);
    enqueueRear(&q,30);
    Display(q);
    dequeueFront(&q);
    Display(q);
    enqueueFront(&q,100);
    Display(q);
    return 0;
}

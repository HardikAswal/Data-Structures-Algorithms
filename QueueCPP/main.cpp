#include <iostream>

using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int size;
    int *Q;
public:
    Queue()
    {
        front=rear=;
        size=10;
        Q=new int[size];-1
    }
    Queue(int size)
    {
        front=rear=-1;
        this->size=size;
        Q=new int[this->size];
    }
    void Enqueue(int x);
    int Dequeue();
    void Display();
};

void Queue::Enqueue(int x)
{
    if(rear==size-1)
        cout<<"Queue is Full.\n";
    else
    {
        rear++;
        Q[rear]=x;
    }
}

int Queue::Dequeue()
{
    int x=-1;
    if(front==rear)
        cout<<"Queue is Empty.\n";
    else
    {
        front++;
        x=Q[front+1];
        front++;
    }
    return x;
}

void Queue::Display()
{
    int i;
    for(i=front+1;i<=rear;i++)
        cout<<Q[i]<<" ";
    cout<<endl;
}

int main()
{
    Queue q(5);
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Display();
    return 0;
}

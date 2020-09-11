#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"

int A[][7]={{0,0,0,0,0,0,0},
            {0,0,1,1,0,0,0},
            {0,1,0,0,1,0,0},
            {0,1,0,0,1,0,0},
            {0,0,1,1,0,1,1},
            {0,0,0,0,1,0,0},
            {0,0,0,0,1,0,0}};
int n=7;

void BFS(int i)
{
   int u,v;
   int visited[7]={0};
   printf("%d ",i);
   visited[i]=1;
   Enqueue(i);

   while(!isEmpty())
   {
       u=Dequeue();
       for(v=1;v<n;v++)
       {
           if(A[u][v]==1 && visited[v]==0)
           {
               printf("%d ",v);
               visited[v]=1;
               Enqueue(v);
           }
       }
   }
}

void DFS(int u)
{
    int v;
    static int visited[7]={0};
    if(visited[u]==0)
    {
        printf("%d ",u);
        visited[u]=1;

        for(v=1;v<n;v++)
        {
            if(A[u][v]==1 && visited[v]==0)
                DFS(v);
        }
    }
}

int main()
{
    DFS(3);
    return 0;
}

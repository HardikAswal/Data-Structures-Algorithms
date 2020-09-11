#include<stdio.h>

int F[10];

int Mfib(int n)
{
    if(n<=1)
    {
        F[n]=n;
        return n;
    }
    else
    {
        if(F[n-2]==-1)
            F[n-2]=Mfib(n-2);
        if(F[n-1]==-1)
            F[n-1]=Mfib(n-1);

        return F[n-2]+F[n-1];
    }


    return 0;
}

int main()
{
    int i;
    for(i=0;i<10;i++)
        F[i]=-1;
    printf("%d\n",Mfib(6));
    return 0;
}

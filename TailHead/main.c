#include <stdio.h>

void fun(int n)
{
    if (n>0)
    {
        printf("\n %d",n);
        fun(n-1);
    }
}
int main()
{
    int x = 4;

    fun(x);
    return 0;
}

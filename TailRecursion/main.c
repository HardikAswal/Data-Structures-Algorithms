#include <stdio.h>
#include <stdlib.h>

void TreeRecursion(int n)
{
    if (n>0)
    {
        printf("%d  ",n);
        TreeRecursion(n-1);
        TreeRecursion(n-1);
    }
}

int main()
{
    TreeRecursion(3);
    return 0;
}

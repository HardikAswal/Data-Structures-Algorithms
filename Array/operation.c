#include<stdio.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

int main()
{
    int i;
    struct Array arr={{2,3,4,5,6},20,5};
    for(i-0;i<arr.length;i++)
        printf("%d",arr.A[i]);



    return 0;
}

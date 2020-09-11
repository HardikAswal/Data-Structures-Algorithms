#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n=10,i;
   int A[]={3,7,4,9,12,6,1,11,2,10};

   int *arr;
   arr=(int *)malloc(n*sizeof(int));

   for(i=0;i<n;i++)
        arr[i]=0;

   for(i=0;i<n;i++){
        arr[A[i]]++;
   }

   for(i=0;i<n;i++){
    if(arr[i]==0)
        printf("%d\n",i);
   }
}

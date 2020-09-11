#include<iostream>

using namespace std;

int main()
{
    char A[]="madame";
    int i,j,notEqual=0;
    for(j=0;A[j]!='\0';j++) {}
    j--;
    for (i=0;A[i]!='\0',i<j;i++,j--)
    {
        if(A[i]!=A[j]){
            notEqual++;
            break;
        }
    }
    if(notEqual>0)
        cout<<"Not a palindrome";
    else
        cout<<"Palindrome";
}


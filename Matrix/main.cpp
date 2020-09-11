#include <iostream>

using namespace std;

class Matrix
{
private:
    int n;
    int *A;

public:
    Matrix(int n)
    {
        this->n=n;
        A=new int[n];
    }

    void Set(int i,int j,int x)
    {
        if(i==j)
            A[i-1]=x;
    }

    int Get(int i,int j)
    {
        if(i==j)
            return A[i-1];
        return 0;
    }

    void Display()
    {
        int i,j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                  if (i==j)
                    cout<<A[i]<<"\t";
                  else
                    cout<<"0\t";
            }
            cout<<endl<<endl;
        }
    }
    ~Matrix()
    {
        delete []A;
    }
};

int main()
{
    //Object
    Matrix m(4);
    m.Set(1,1,5);
    m.Set(2,2,8);
    m.Set(3,3,9);
    m.Set(4,4,12);
    m.Display();
    return 0;
}

#include<iostream>
using namespace std;

void search(int[]);

int main()
{
    int A[3]={98,46,703};
    search(A);
    system("pause");
}

void search(int B[])
{
    int i=0, value;
    cout<<"Enter the value to find: ";
    cin>>value;

    while(i<=2)
    {
        if(B[i]==value)
        {
            cout<<"Found the value "<<value<<" at "<<i<<endl;
            break;
        }
        else
        {
            cout<<"Not Found the value "<<value;
        }
        i++;
    }
    
}
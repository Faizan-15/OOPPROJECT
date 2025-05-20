#include<iostream>
using namespace std;

int main()
{
    int q=12, w=88;
    cout<<"Values of two numbers of q and w before swapping are: "<<q<<" and "<<w<<endl;
    q=q+w;
    w=q-w;
    q=q-w;
    cout<<"Values of two numbers of q and w after swapping are: "<<q<<" and "<<w<<endl;

    system("pause");
}
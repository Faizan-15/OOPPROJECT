#include<iostream>
using namespace std;

int main()
{
    float o, p, temp;
    cout<<"Enter first value: ";
    cin>>o;
    cout<<"Enter second value: ";
    cin>>p;
    cout<<"Before swapping: "<<endl;
    cout<<"First Value: "<<o<<endl;
    cout<<"Second Value: "<<p<<endl;
    temp = o;
    o=p;
    p=temp;
    cout<<"After swapping: "<<endl;
    cout<<"First Value: "<<o<<endl;
    cout<<"Second Value: "<<p<<endl;
    
    system("pause");
}
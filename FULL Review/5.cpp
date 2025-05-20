#include<iostream>
using namespace std;

int main()
{
    float metre, kilometer;
    cout<<"Enter the distance in metre: ";
    cin>>metre;
    cout<<"Distance in Kilometer: "<<metre/1000<<endl<<endl;

    cout<<"Enter distance in Kilometer: ";
    cin>>kilometer;
    cout<<"Distance in Metre: "<<kilometer*1000<<endl<<endl;

    system("pause");
}
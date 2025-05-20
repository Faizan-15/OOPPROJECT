#include<iostream>
using namespace std;

int main()
{
    float c, d;
    //Addition
    cout<<"Addition\n\n";
    cout<<"Enter a First Number: ";
    cin>>c;
    cout<<"Enter a Second Number: ";
    cin>>d;
    cout<<"Sum of "<<c<<" and "<<d<<" is: "<<c+d<<"\n\n\n";
    //Subtraction
    cout<<"Subtraction\n\n";
    cout<<"Enter a First Number: ";
    cin>>c;
    cout<<"Enter a Second Number: ";
    cin>>d;
    cout<<"Subtraction of "<<c<<" and "<<d<<" is: "<<c-d<<endl<<endl<<endl;
    //Multiplication
    cout<<"Multiplication\n\n";
    cout<<"Enter a First Number: ";
    cin>>c;
    cout<<"Enter a Second Number: ";
    cin>>d;
    cout<<"Product of "<<c<<" and "<<d<<" is: "<<c*d<<endl<<endl<<endl;
    //Division
    cout<<"Division\n\n";
    cout<<"Enter a First Number: ";
    cin>>c;
    cout<<"Enter a Second Number: ";
    cin>>d;
    cout<<"Division of "<<c<<" and "<<d<<" is: "<<c/d<<endl<<endl<<endl;
    system("pause");
}
#include<iostream>
using namespace std;

void TOH(int, char, char, char);

int main()
{
    int n;
 
    cout<<"Enter the number of disks: ";
    cin>>n;
 
    TOH(n, 'L', 'N', 'M');
    system("pause");

    return 0;
}

void TOH (int r, char x, char y, char z)
{
    if (r!=0)
    {
        TOH (r-1, x, z, y);
        cout<<"Disk moved "<<r<<" from "<<x<<" to "<<y<<endl;
        TOH (r-1, z, y, x);
    }
}
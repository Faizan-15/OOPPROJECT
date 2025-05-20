#include<iostream>
using namespace std;

void Swap(int ***s1, int *s2)
{
	int temp;
	temp = ***s1;
	***s1 = *s2;
	*s2 = temp;
}

int main()
{
	int x=10, y=20, *p1, **p2, ***p3, *yptr;
	p1=&x;
	p2=&p1;
	p3=&p2;
	yptr=&y;
	cout<<"Before swapping: \n\n";
	cout<<"x: \n"<<x<<endl<<p3<<endl<<"\ny: \n"<<y<<endl<<yptr<<"\n\n\n";
	Swap(p3, yptr);
	cout<<"After swapping: \n\n";
	cout<<"x: \n"<<x<<endl<<p3<<endl<<"\ny: \n"<<y<<endl<<yptr<<"\n\n\n";
	system("pause");
}

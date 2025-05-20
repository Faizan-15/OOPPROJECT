#include<iostream>
#include<string>

using namespace std;

void SortNames(string *s1)
{
	string *s2, temp;
	s2=s1;
	for(int i=0; i<5; i++)
	{
		s2=s1;
		for(int j=i+1; j<5; j++)
		{
			s2++;
			if(*s1>*s2)
			{
				temp = *s1;
				*s1=*s2;
				*s2=temp;
			}
		}
		s1++;
	}
}
int main()
{
	string s[5]={"Talha", "Mehmood", "Asif", "Waqar", "Malik"};
	SortNames(s);
	for(int  i=0;  i<5; i++)
	{
		cout<<s[i]<<"\t";
	}
}

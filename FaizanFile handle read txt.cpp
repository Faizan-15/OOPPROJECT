#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	char ch;
	ifstream ifs;
	ifs.open("data.txt"ios::app);
	if(!ifs)
	{
		cerr<<"Error opening the file.\n";
	}
	
	while(!ifs.eof())
	{
		ifs.get(ch);
		cout<<ch;
	}
	ifs.close();
	//ifstream reads from text file
	
	//ofstream writes in text file
	
}
#include<iostream>
using namespace std;

class InvertorSupply
{
	private:
			int Electricity;
	public:
			InvertorSupply(int E)
			{
				Electricity=E;
				cout<<"Invertor Supplies: "<<Electricity<<" Watts of Power.\n";
			}
};

class InvertorInfo
{
	private:
			string Name;
	public:
			InvertorInfo(string N)
			{
				Name=N;
				cout<<"Name: "<<Name<<endl;
			}
};

class DataFetcher:public InvertorInfo,InvertorSupply
{
	public:
			DataFetcher(float Current, int e, string n) : InvertorInfo(n), InvertorSupply(e)
			{
				cout<<"Current: "<<Current<<endl;
			}
};

int main()
{
	DataFetcher df(12.9,5000,"Inverex");
	return 0;
}

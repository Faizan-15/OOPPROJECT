#include<iostream>
#include<fstream>

using namespace std;
struct student
{
	int s_id;
	char name[20];
	float gpa;
};

void writeRecord();
void readRecord();
void editRecord();
void searchRecord();
void deleteRecord();

int main()
{
	ifstream ifs;
	int choice;
	char opt;
	
	do
	{
		cout<<"Enter 1 to Write Records in text file \n";
		cout<<"Enter 2 to Read Records from text file \n";
		cout<<"Enter 3 to Edit Records of text file \n";
		cout<<"Enter 4 to Search Records from text file \n";
		cout<<"Enter 5 to Delete Records from the text file \n";
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				writeRecord();
				break;
			case 2:
				readRecord();
				break;
			case 3:
				editRecord();
				break;
//			case 4:
//				searchRecord();
//				break;
//			case 5:
//				deleteRecord();
//				break;
			default:
				cout<<"Invalid Input!";
		}
		cout<<"Press y or Y to continue: ";
		cin>>opt;
	}while(opt=='y'||opt=='Y');
	
}

void writeRecord()
{
	ofstream ofs;
	ofs.open("data.txt", ios::app);
	student s;
	cout<<"Enter Roll Number of Student: ";
	cin>>s.s_id;
	cout<<"Enter Name of Student: ";
	cin>>s.name;
	cout<<"Enter GPA of Student; ";
	cin>>s.gpa;
	ofs<<s.s_id<<"\t"<<s.name<<"\t"<<s.gpa<<endl;
	ofs.close();
}

void readRecord()
{
	ifstream ifs;
	ifs.open("data.txt");
	student s;
	ifs>>s.s_id;
	ifs>>s.name;
	ifs>>s.gpa;
	while(!ifs.eof())
	{
		cout<<s.s_id<<"\t"<<s.name<<"\t"<<s.gpa<<endl;
		ifs>>s.s_id;
		ifs>>s.name;
		ifs>>s.gpa;
	}
	ifs.close();
}

void editRecord()
{
	ifstream ifs;
	ifs.open("data.txt");
	
	ofstream ofd;
	ofd.open("data2.txt");
	
	int id;
	cout<<"Enter Student Id to edit its record: ";
	cin>>id;
	
	student s;
	ifs>>s.s_id;
	ifs>>s.name;
	ifs>>s.gpa;
	
	while(!ifs.eof())
	{
		if(id==s.s_id)
		{
			cout<<"Enter id of student: ";
			cin>>s.s_id;
			cout<<"Enter name of student: ";
			cin>>s.name;
			cout<<"Enter GPA of student: ";
			cin>>s.gpa;
			ofd<<s.s_id<<"\t"<<s.name<<"\t"<<s.gpa<<endl;
		}
		
		else
		{
			ofd<<s.s_id<<"\t"<<s.name<<"\t"<<s.gpa<<endl;
		}
		ifs>>s.s_id;
		ifs>>s.name;
		ifs>>s.gpa;
	}
	ifs.close();
	ofd.close();
	remove("data.txt");
	rename("data2.txt","data.txt");
}

//void searchRecord()
//void deleteRecord()

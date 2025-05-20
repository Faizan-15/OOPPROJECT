#include<iostream>
#include<fstream>
#include<conio.h>
#include<string>
#include<sstream>
#include<windows.h>

using namespace std;

void student(string,string);//CODE IS AT 100 LINE
void edit_std();//CODE IS AT 425 LINE
void see_std();//CODE IS AT 408 LINE
void teacher(string,string);//CODE IS AT 143 LINE
void edit_tea();//PENDING
void see_tea();//PENDING
void admin(string, string);//CODE IS AT 182 LINE 
void edit_admin();//PENDING
void see_admin();//PENDING
void see_attend();//CODE IS AT 242 LINE
void in_attend();//CODE IS AT 255 LINE
void see_timetable();//CODE IS AT 226 LINE
void in_timetable();//CODE IS AT 322 LINE
void see_adporatal();//CODE IS AT 382 LINE
void see_faculity();//CODE IS AT 395 LINE
int main()
{
	system("color 71");
	string name,pass;
	char ch,ch1;
	int choice;
	cout<<"Press 1 for student login "<<endl;
	cout<<"Press 2 for teacher login "<<endl;
	cout<<"Press 3 for admin login   "<<endl;
	cout<<"Press 4 for kicsit info "<<endl;
	cout<<"Choice :";
	cin>>choice;
	system("cls");
	if(choice==1)
	{
		cin.ignore();
		cout<<"Enter student name :";
		getline(cin,name);
		cout<<"Enter password of student id :";
		ch=getch();
		while(ch!=13)
		{
			pass.push_back(ch);
			cout<<"*";
			ch=getch();
		}
		student(name,pass);
	}
	if(choice==2)
	{
		cin.ignore();
		cout<<"enter teacher name :";
		getline(cin,name);
		cout<<"enter password of teacher id :";
		ch=getch();
		while(ch!=13)
		{
			pass.push_back(ch);
			cout<<"*";
			ch=getch();
		}
		teacher(name,pass);
	}
	if(choice==3)
	{
		cin.ignore();
		cout<<"enter admin name :";
		getline(cin,name);
		cout<<"enter password of admin id :";
		ch=getch();
		while(ch!=13)
		{
			pass.push_back(ch);
			cout<<"*";
			ch=getch();
		}
		admin(name,pass);
	}
	if(choice==4)
	{ 
      char opt;
		cout<<"press 1 to see admission portal "<<endl;
		cout<<"press 2 to see faculity data "<<endl;
		cout<<"choice :";
		cin>>opt;
		if(opt=='1')
		{
			 see_adporatal();
		}
		if(opt=='2')
		{
			 see_faculity();
		}
    }
}//student__________________________________________________________________________________________________
void student(string name,string pass)
{
	char stdch,ch;
//	string temp;
    string line,a[11][3];
	ifstream fin;
	fin.open("STD.RECORD.txt");
	stringstream sep;
		for(int i=0;i<11;i++)
		{
			getline(fin,line);
			cout<<line;
			sep.clear();
			sep.str(line);
			for(int j=0;j<3;j++)
			{
		   getline(sep,a[i][j],'|');
	        }
	   }
    fin.close();
    for(int i=0;i<11;i++)
    {
    	if(a[i][1]==name)
         {
    		if(a[i][2]==pass)
    		{
    			do{
    			system("cls");
    			cout<<"press 1 to see attendence "<<endl;
    			cout<<"press 2 to see time table "<<endl;
    			cout<<"press 3 to solve quiz "<<endl;
    			cout<<"choice :";
    			cin>>stdch;
    			if(stdch=='1')
    			{
    			see_attend();
				}
				else if(stdch=='2')
				{
					see_timetable();
				}
				cout<<"--------press y to continue---------- ";
				cin>>ch;
			}while(ch=='y'||ch=='Y');
			}
		}
    }
}

//teacher____________________________________________________________________________________
void teacher(string name,string pass)
{
	string a[10];
	char techo,ch;
	ifstream fin;
	fin.open("namepass.th.txt");
	for(int i=0;i<10;i++)
	{
		getline(fin,a[i]);
	}
    fin.close();
    for(int i=0;i<10;i++)
    {
    	if(a[i]==name)
    	{
    		if(a[i+1]==pass)
    		{
    			do{
    			cout<<"\npress 1 to take attendence "<<endl;
    			cout<<"press 2 to see time table "<<endl;
    			cout<<"press 3 to take quiz "<<endl;
    			cout<<"press 4 to see student record "<<endl;
    			cout<<"choice :";
    			cin>>techo;
    			if(techo=='1')
    			{
    				in_attend();
				}
				else if(techo=='2')
				{
					see_timetable();
				}
				else if(techo=='4')
				{
					see_std();
				}
				cout<<"---------press y to continue---------";
				cin>>ch;
			}while(ch=='y'||ch=='Y');
			}
			else
			{
				cout<<"\nacess denied";
				break;
			}
		}
	}	
}//admin_______________________________________________________________________________________________
void admin(string name,string pass)
{
	string a[10];
	ifstream fin;
	char adchoice,ch;
	fin.open("namepass.adm.txt");
	for(int i=0;i<10;i++)
	{
		getline(fin,a[i]);
	}
    fin.close();
    for(int i=0;i<10;i++)
    {
    	if(a[i]==name)
    	{
    		if(a[i+1]==pass)
    		{
    			do{
    			cout<<"\npress 1 to see time table";
    			cout<<"\npress 2 to edit time table";
    			cout<<"\npress 3 to see student record";
    			cout<<"\npress 4 to edit student record";
    			cout<<"\npress 5 to see teacher record";
    			cout<<"\npress 6 to edit teacher record";
    			cout<<"\nchoice :";
    			cin>>adchoice;
    			if(adchoice=='1')
	            {
	             	see_timetable();
               	}
               	else if(adchoice=='2')
	            {
	           	in_timetable();
	            }
	            else if(adchoice=='3')
	            {
	            	see_std();
				}
				else if(adchoice=='4')
	            {
	            	edit_std();
				}
				else if(adchoice=='5')
	            {
	            	see_tea();
				}
				else if(adchoice=='3')
	            {
	            	edit_tea();
				}
	            cout<<"----------press y to continue------------";
	            cin>>ch;
	            system("cls");
	        }while(ch=='y'||ch=='Y');
			}
		}
	}
}
void see_timetable()
{
	string a[11];
    ifstream fin;
	fin.open("timetable2.txt");
	
		for(int i=0;i<11;i++)
		{
			getline(fin,a[i]);
			cout<<a[i]<<endl;
		}
	fin.close();
}
void see_attend()
{
	string a[11],line;
	ifstream fin;
	fin.open("attendence-practice.txt");
	for(int i=0;i<11;i++)
	{
		getline(fin,line);
		cout<<line<<endl;
	}
	fin.close();
}
void in_attend()
{
	system("cls");
	int k;
	ifstream finp;
	finp.open("colindex.txt");
	finp>>k;
	finp.close();
	ofstream fiout;
	fiout.open("colindex.txt");
	fiout<<++k;
	fiout.close();
string a[10][k],line;
	ifstream fin;
	fin.open("attendence-practice.txt");
	stringstream sep;
	for(int i=0;i<10;i++)
	{
		getline(fin,line);
		sep.clear();
		sep.str(line);
		for(int j=0;j<k;j++)
		{
			getline(sep,a[i][j],'|');
		}
	}
	fin.close();
	ofstream fout;
	char aten;
	fout.open("attendence-practice.txt");
	for(int i=0;i<10 ;i++)
	{
		for(int j=0;j<k;j++)
		{
			if(j>k-2)
			{
				en:
				cout<<"enter attendence of roll no "<<a[i][1]<<" :";
				cin>>aten;
				if(aten=='a'||aten=='A'||aten=='p'||aten=='P')
				{
					a[i][j]=toupper(aten);
				}
				else
				{
					cout<<"wrong input try again "<<endl;
					goto en;
				}
			}
			fout<<a[i][j]<<"|";
		}
		fout<<endl;
	}
	fout.close();
	system("cls");
	fin.open("attendence-practice.txt");
	if(!fin.is_open())
	{
		cout<<"error ";
	}
    string output;
    while (getline(fin, output)) 
	{ 
        cout << output << endl;
    }
    fin.close();
}
void in_timetable()
{
		int i=11,j=5;
	string a[i][j],day,line;
	ofstream fout;
	ifstream fin;
	stringstream sep;
	fin.open("timetable2.txt");
		for(int i=0;i<11;i++)
		{
		getline(fin,line);
		sep.clear();
		sep.str(line);	
			for(int j=0;j<5;j++)
			{
				getline(sep,a[i][j],'|');
			}
	     }
	     fin.close();
	 int dayn;
	cout<<"for edit provide day number(1-5) :";
	cin>>dayn;	
	fout.open("timetable2.txt");
	for(int i=0;i<11;i++)
	{
		if(i/2==dayn)
		{
				cin.ignore();
		for(int j=0;j<5;j++)
			{
				if(i>0&&j>0&&(i%2==0))
				{
			    cout<<"enter data of "<<i/2<<" row and "<<j<<" colmn _";
				getline(cin,a[i][j]);
				}		
			}
	    }
	}
	for(int i=0;i<11;i++)
	{
		for(int j=0;j<5;j++)
		{
	     
		       fout<<a[i][j]<<"|";	
		}
		fout<<endl;
	}
	system("cls");
	fout.close();
	fin.open("timetable2.txt");
		for(int i=0;i<11;i++)
		{
			for(int j=0;j<5;j++)
			{
				cout<<a[i][j]<<"|";
			}
			cout<<endl;
		}
	fin.close();
}
void see_adporatal()
{
	string line;
	ifstream fin;
	fin.open("admissionportal.txt.txt");
	cout<<"                        ADMISSION  PORTAL  KICSIT 2024                        "<<"\n"<<"\n";
	while(!fin.eof())
	{
    getline(fin,line);
    cout<<line<<"\n";
    }
    fin.close(); 
}
void see_faculity()
{
	
	string line;
	ifstream fin;
	fin.open("facultydata.txt");
	while(!fin.eof())
	{
		getline(fin,line);
		cout<<line<<"\n";
	}
	fin.close();
}
void see_std()
{
	int j=0;
	string a[20];
	ifstream fin;
	fin.open("STD.RECORD.txt");
		for(int i=0;!fin.eof();i++)
		{
		getline(fin,a[i]);
		j++;
	    }
	
	fin.close();
	
	for(int i=0;i<j;i++)
	{
		cout<<a[i]<<endl;
	}
}

void edit_std()
{
	int x=0;
	string rn,line,a[11][3];
	ifstream fin;
	fin.open("STD.RECORD.txt");
	stringstream sep;
	
	for(int i=0;i<11;i++)
		{
			getline(fin,line);
			sep.clear();
			sep.str(line);
			for(int j=0;j<3;j++)
			{
		   		getline(sep,a[i][j],'|');
	        }
	    }

	for(int i=0;i<11;i++)
    {
	   	for(int j=0;j<3;j++)
	   	{
	   		cout<<a[i][j]<<"|";
	    }
	    cout<<endl;
    }

   	cout<<"enter the roll number :";
   	cin>>rn;

   	for(int i=0;i<11;i++)
   	{
   		for(int j=0;j<3;j++)
   		{
   			if(j<1&&i>0)
   			{
   				if(rn==a[i][j])
			   	{
					cout<<"enter the edited name :";
					cin.ignore();
					getline(cin,a[i][1]);
					cout<<"enter the edited password :";
					cin>>a[i][2];
				}	
			}
		}
    }
   	ofstream fout;
	fout.open("STD.RECORD.txt");
    
	for(int i=0;i<11;i++)
   	{
   		for(int j=0;j<3;j++)
   		{
   			fout<<a[i][j]<<"|";
   			cout<<a[i][j]<<"|";
		}
		fout<<endl;
		cout<<endl;
    }

	fin.close();
	fout.close();
}
void see_tea()//WORK IN PROGRESS
{
	string line ;
	ifstream fin;
	fin.open("th.record.txt");
	
	for(int i=0;!fin.eof();i++)
	{
		getline(fin,line);
		cout<<line<<endl;
	}
	
	fin.close();
}

void edit_tea()//WORK IN PROGRESS
{	
	string line ,a[5][4];
    ifstream fin;
	fin.open("th.record.txt");
	stringstream sep;

	for(int i=0;i<5;i++)
	{
		getline(fin,line);
		sep.clear();
		sep.str(line);
		for(int j=0;j<4;j++)
		{
			getline(sep,a[i][j],'|');
		}
	}

	fin.close();
	
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<a[i][j]<<"|";
		}
		cout<<endl;
	}
	
	string id;
	cout<<"enter the teacher id :";
	cin>>id;
	ofstream fout;
	fout.open("th.record.txt");
	
	for(int i=0;i<5;i++)
	{
		if(id==a[i][0])
		{
			cout<<"enter the edited teacher name :";
			cin>>a[i][1];
			cout<<"enter the edited subject :";
			cin>>a[i][2];
		}
		
	}
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<a[i][j]<<"|";
			fout<<a[i][j]<<"|";
		}
		fout<<endl;
		cout<<endl;
	}
}
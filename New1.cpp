#include<iostream>
using namespace std;

class BankAccount
{
      private:
              int accountnumber=12345678, balance=55000, pin=1234;
      public:
             void show_account_info();
             void show_account_balance();
};

int main()
{
    BankAccount BA;
    BA.show_account_info();
    BA.show_account_balance();
}

void BankAccount::show_account_info()
{
     int q;
     cout<<"Enter your pin to see Account Number: ";
     cin>>q;
     if(q==pin)
     {
               cout<<"Account Number: "<<accountnumber<<endl;
     }
}

void BankAccount::show_account_balance()
{
     int w;
     cout<<"Enter your pin to see Account Balance: ";
     cin>>w;
     if(w==pin)
     {
               cout<<"Account Number: "<<accountnumber<<endl<<"Balance: "<<balance<<endl;
     }
     system("pause");
}
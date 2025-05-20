#include <iostream>
#include <string>

using namespace std;

// Variable Declarations and initiaizations if needed
const int MAX_ACCOUNTS = 100;
int accountNumbers[MAX_ACCOUNTS];
string names[MAX_ACCOUNTS];
double balances[MAX_ACCOUNTS];
int totalAccounts = 0;

// Function Prototypes
void CreateAccount();
void ShowAccounts();
void Deposit();
void Withdrawal();
void Search();

int main()
{
    int choice;

    do {
    	cout << "************************************************************************************************************************" << endl;
        cout << "*                                               --- Bank Management System ---                                         *" << endl;
        cout << "*                                               1. Create Account                                                      *" << endl;
        cout << "*                                               2. Show Accounts                                                       *" << endl;
        cout << "*                                               3. Deposit                                                             *" << endl;
        cout << "*                                               4. Withdrawal                                                          *" << endl;
        cout << "*                                               5. Search                                                              *" << endl;
        cout << "*                                               6. Exit                                                                *" << endl;
        cout << "************************************************************************************************************************" << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            CreateAccount();
            system("cls");
            break;
        case 2:
            ShowAccounts();
            system("cls");
            break;
        case 3:
            Deposit();
            system("cls");
            break;
        case 4:
            Withdrawal();
            system("cls");
            break;
        case 5:
            Search();
            system("cls");
            break;
        case 6:
            system("cls");
            cout << "Exiting system. Goodbye!" << endl;
            system("pause");
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            system("pause");
            system("cls");
        }
    } while (choice != 6);
    
    return 0;
}

void CreateAccount()
{
    if (totalAccounts >= MAX_ACCOUNTS)
    {
        cout << "Maximum account limit reached. Cannot create more accounts." << endl;
        return;
    }

    int accNum;
    string accName;
    double openingBalance;

    cout << "Enter account number: ";
    cin >> accNum;
    cout << "Enter name (without spaces): ";
    cin >> accName;
    cout << "Enter opening balance: ";
    cin >> openingBalance;

    accountNumbers[totalAccounts] = accNum;
    names[totalAccounts] = accName;
    balances[totalAccounts] = openingBalance;
    totalAccounts++;

    cout << "\nAccount created successfully." << endl;

    system("pause"); // Pause to allow user to see the created account
}

void ShowAccounts()
{
    if (totalAccounts == 0)
    {
        cout << "\nNo accounts to display." << endl;
        return;
    }

    for (int i = 0; i < totalAccounts; ++i)
    {
        cout << "\nAccount Number: " << accountNumbers[i] << endl;
        cout << "Name: " << names[i] << endl;
        cout << "Balance: " << balances[i] << endl;
    }

    system("pause"); // Pause to allow user to see the accounts
}

void Deposit()
{
    int accNum;
    double amount;
    cout << "\nEnter account number: ";
    cin >> accNum;

    for (int i = 0; i < totalAccounts; i++)
    {
        if (accountNumbers[i] == accNum)
        {
            cout << "Enter amount to deposit: ";
            cin >> amount;
            if (amount > 0)
            {
                balances[i] += amount;
                cout << "Amount deposited successfully. New Balance: " << balances[i] << endl;
                system("pause"); // Pause to allow user to see deposited money in the account
            } else
            {
                cout << "Invalid amount. Deposit failed." << endl;
            }
            return;
        }
    }

    cout << "\nAccount not found." << endl;
    system("pause"); // Pause to allow user to see no account found for deposit
}

void Withdrawal()
{
    int accNum;
    double amount;
    cout << "\nEnter account number: ";
    cin >> accNum;

    for (int i = 0; i < totalAccounts; i++)
    {
        if (accountNumbers[i] == accNum)
        {
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            if (amount > 0 && amount <= balances[i])
            {
                balances[i] -= amount;
                cout << "Amount withdrawn successfully. Remaining Balance: " << balances[i] << endl;
                system("pause"); // Pause to allow user to see withdrawn money from the account
            }
            else if (amount > balances[i])
            {
                cout << "\nInsufficient balance. Withdrawal failed." << endl;
                system("pause"); // Pause to allow user to see the error that failed the withdrawal from the account
            }
            else
            {
                cout << "\nInvalid amount. Withdrawal failed." << endl;
                system("pause"); // Pause to allow user to see the error that invalid amount has been entered for withdrawal
            }
            return;
        }
    }

    cout << "\nAccount not found." << endl;
    system("pause"); // Pause to allow user to see no account found for withdrawal
}

void Search()
{
    int accNum;
    cout << "\nEnter account number to search: ";
    cin >> accNum;
    cout << endl;

    for (int i = 0; i < totalAccounts; i++)
    {
        if (accountNumbers[i] == accNum)
        {
            cout << "Account found: \n" << endl;
            cout << "Account Number: " << accountNumbers[i] << endl;
            cout << "Name: " << names[i] << endl;
            cout << "Balance: " << balances[i] << endl << endl;
            system("pause"); // Pause to allow user to see the searched account
            return;
        }
    }

    cout << "\nAccount not found." << endl;
}
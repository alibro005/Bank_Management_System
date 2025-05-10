#include <iostream>
#include <string>
using namespace std;

#define MAX_ACCOUNTS 100
int accountNumbers[MAX_ACCOUNTS];
double accountBalances[MAX_ACCOUNTS];
string accountHoldernames[MAX_ACCOUNTS];
int totalaccounts = 0;

void menu();
void createAccounts();
void depositMoney();
void withdrawMoney();
void displayBalance();

int main()
{
    for (int i = 0; i <= 5; i++)
    {
        menu();
    }
    return 0;
}

void menu()
{
    int choice;
    cout << "____________Bank Management System___________" << endl;
    cout << "1. Create New Account" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Display Balance" << endl;
    cout << "5. Exit (Thanks for using this)" << endl;
    cout<<"Enter your choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        createAccounts();
        break;
    case 2:
        depositMoney();
        break;
    case 3:
        withdrawMoney();
        break;
    case 4:
        displayBalance();
        break;
    case 5:
        cout << "Thanks For Using" << endl;
        break;
    default:
        cout << "Invalid choice. Try again." << endl;
        break;
    }
}

void createAccounts()
{
    if (totalaccounts >= MAX_ACCOUNTS)
    {
        cout << "Accounts Limit reached" << endl;
        return;
    }
    int accountNumber;
    string accountHoldername;
    double initialDeposit;

    cout << "Enter Account Number : ";
    cin >> accountNumber;
    cout << "Enter Account Holder Name : ";
    cin.ignore();
    getline(cin, accountHoldername);
    cout << "Enter Initial Deposit : $ ";
    cin >> initialDeposit;

    accountNumbers[totalaccounts] = accountNumber;
    accountBalances[totalaccounts] = initialDeposit;
    accountHoldernames[totalaccounts] = accountHoldername;
    totalaccounts++;

    cout << "Account Created Successfully" << endl;
}

void depositMoney()
{
    int accountNumber;
    double amount;
    cout << "Enter Account Number : ";
    cin >> accountNumber;
    bool accountFound = false;

    for (int i = 0; i < totalaccounts; i++)
    {
        if (accountNumbers[i] == accountNumber)
        {
            cout << "Enter Amount to Deposit:$ ";
            cin >> amount;
            accountBalances[i] += amount;
            cout << "Amount Deposited Successfully" << endl;
            accountFound = true;
            break;
        }
    }

    if (!accountFound)
    {
        cout << "Wrong Account Number or Account Does Not Exist" << endl;
    }
}

void withdrawMoney()
{
    int accountNumber;
    double amount;
    cout << "Enter Account Number : ";
    cin >> accountNumber;
    bool accountFound = false;

    for (int i = 0; i < totalaccounts; i++)
    {
        if (accountNumbers[i] == accountNumber)
        {
            cout << "Enter Amount to Withdraw: ";
            cin >> amount;

            if (amount > accountBalances[i])
            {
                cout << "Insufficient Balance" << endl;
            }
            else
            {
                accountBalances[i] -= amount;
                cout << "Amount Withdrawn Successfully" << endl;
            }
            accountFound = true;
            break;
        }
    }

    if (!accountFound)
    {
        cout << "Wrong Account Number or Account Does Not Exist" << endl;
    }
}

void displayBalance()
{
    if (totalaccounts == 0)
    {
        cout << "No Accounts Found" << endl;
        return;
    }

    int accountNumber;
    cout << "Enter Account Number : ";
    cin >> accountNumber;
    bool accountFound = false;

    for (int i = 0; i < totalaccounts; i++)
    {
        if (accountNumbers[i] == accountNumber)
        {
            cout << "\n_______Account Balance_______" << endl;
            cout << "Account Number  \t Balance" << endl;
            cout << accountNumbers[i] << "\t\t\t" << accountBalances[i] << endl;
            accountFound = true;
            break;
        }
    }

    if (!accountFound)
    {
        cout << "Wrong Account Number or Account Does Not Exist" << endl;
    }
}

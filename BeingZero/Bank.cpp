//#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <exception>
#include <limits>
#include <fstream>

#define MAX 1000

using namespace std;

int month, index;
ofstream outfile;
ifstream infile;

typedef struct transactions transactions;
struct transactions
{
    string type;
    double amount;
    string time;
};

transactions details[MAX];

class Account
{
public:
    string accountNumber, name;
    Account();
    Account(string accountNumber, string name)
    {
        this->accountNumber = accountNumber;
        this->name = name;
    }

public:
    virtual void accountInformation();

    virtual void deposit(double amount);
};

Account::Account()
{
}

void Account::accountInformation()
{
}

void Account::deposit(double amount)
{
}

class Savings : Account
{
public:
    double balanceAmount = 0;

    Savings();

    void deposit(double amount)
    {
        outfile.open("Transactions.txt", ofstream::out | ofstream::app);
        time_t now = time(0);
        details[index].amount = amount;
        details[index].type = "Deposit";
        details[index].time = ctime(&now);
        outfile << "Type = " << details[index].type << " Amount = " << details[index].amount << " Time = " << details[index].time << "\n";
        outfile.close();
        index++;
        cout << "Deposited an amount of " << amount << " in savings account \n";
        balanceAmount = amount;
    }
    
    void withDrawal(double amount)
    {
        if (!checkBalance() || amount >= balanceAmount)
        {
            cout << "No balance left \n";
            return;
        }
        outfile.open("Transactions.txt", ofstream::out | ofstream::app);
        time_t now = time(0);
        details[index].amount = amount;
        details[index].type = "Withdrawal";
        details[index].time = ctime(&now);
        outfile << "Type = " << details[index].type << " Amount = " << details[index].amount << " Time = " << details[index].time << "\n";
        outfile.close();
        index++;
        cout << "Amount withdrawn : " << amount << " \n";
        balanceAmount -= amount;
    }

    void deductBalance(double amount)
    {
        balanceAmount -= amount;
    }

    bool checkBalance()
    {
        return balanceAmount > 0;
    }

    void accountInformation(Account acc)
    {
        cout << "Savings Balance for account number : " << acc.accountNumber << " is  : " << balanceAmount << "\n";
    }

    void displayTransactionDetails()
    {
        string line;
        infile.open("Transactions.txt");

        if (infile.is_open())
        {
            while (getline(infile, line))
                cout << line << '\n';
            infile.close();
        }
    }
};

class FixedDeposit : Account
{
public:
    FixedDeposit();
    double depositAmount = 0, balanceAmount = 0, rate = 0.0;

    void setDepositAmount(double amount)
    {
        depositAmount = amount;
    }

    void deposit(Savings &s)
    {
        cout << "Credited amount of Rs." << depositAmount << " in Fixed Deposit\n";
        balanceAmount += depositAmount;
        s.balanceAmount -= depositAmount;
    }

    void accountInformation(Account acc)
    {
        cout << "Fixed Deposit Balance for account number : " << acc.accountNumber << " is  : " << balanceAmount << "\n";
    }
};

Savings::Savings()
{
}

FixedDeposit::FixedDeposit()
{
}

void calculateInterest(int time, int rate, double &principle)
{
    principle += (principle * rate * time) / (100 * 12);
    cout << "Interest added!\n";
}

void checkInputFromUser(double &depositAmount)
{
    while (true)
    {
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid ! Enter a Number: ";
            cin >> depositAmount;
        }

        if (depositAmount <= 0)
        {
            cout << "Enter a number more than 0: ";
            cin >> depositAmount;
            continue;
        }

        break;
    }
}

void checkInputFromUser(int &choice)
{
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid ! Enter correct choice : ";
        cin >> choice;
    }
}

int main()
{
    try
    {
        int choice, time;
        double rateOfInterest, depositAmountSavings, withdrawalAmountSavings, depositAmountFixedDeposit;
        char yesorno;
        Account acc("127AXC810", "Hemant");
        Savings s;
        FixedDeposit fd;

        do
        {
            cout << "1 - Deposit amount in Savings\n2 - Withdraw amount from Savings\n3 - Deposit amount in Fixed Deposit\n4 - Calculate Interest for Savings\n5 - Calculate interest for Fixed Deposit\n6 - View transaction logs\n7 - Check balance in Savings\n8 - Check balance in Fixed Deposit\n";
            cout << "Enter your choice : ";
            cin >> choice;
            checkInputFromUser(choice);
            switch (choice)
            {
            case 1:
                cout << "Enter Deposit amount : ";
                cin >> depositAmountSavings;
                checkInputFromUser(depositAmountSavings);
                s.deposit(depositAmountSavings);
                break;
            case 2:
                cout << "Enter Withdrawal amount : ";
                cin >> withdrawalAmountSavings;
                checkInputFromUser(withdrawalAmountSavings);
                s.withDrawal(withdrawalAmountSavings);
                break;
            case 3:
                cout << "Enter Deposit amount : ";
                cin >> depositAmountFixedDeposit;
                checkInputFromUser(depositAmountFixedDeposit);
                fd.setDepositAmount(depositAmountFixedDeposit);
                fd.deposit(s);
                break;
            case 4:
                cout << "Enter the time period in months : ";
                cin >> time;
                cout << "Enter the rate of interest : ";
                cin >> rateOfInterest;
                calculateInterest(time, rateOfInterest, s.balanceAmount);
                break;
            case 5:
                cout << "Enter the time period in months : ";
                cin >> time;
                cout << "Enter the rate of interest : ";
                cin >> rateOfInterest;
                calculateInterest(time, rateOfInterest, fd.balanceAmount);
                break;
            case 6:
                s.displayTransactionDetails();
                break;
            case 7:
                s.accountInformation(acc);
                break;
            case 8:
                fd.accountInformation(acc);
                break;
            default:
                cout << "Invalid choice\n";
            }

            while (true)
            {
                cout << "\nDo you want to continue (Y/N) : ";
                cin >> yesorno;
                if (yesorno != 'Y' && yesorno != 'N')
                {
                    cout << "Enter only Y/N \n";
                    continue;
                }
                break;
            }
            
        } while (yesorno == 'Y');
    }
    catch (exception &e)
    {
        cerr << "exception caught: " << e.what() << '\n';
    }
}

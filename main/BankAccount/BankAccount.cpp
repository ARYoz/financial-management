#include "BankAccount.h"
#include "Salary.h"
#include"ApartmentRental.h"
#include "SocialSecurity.h"
#include "Unofficialincome.h"
#include "FixedExpense.h"
#include "OneTimeExpense.h"
#include "CombinedExpense.h"
#include <iostream>
using namespace std;

BankAccount::~BankAccount()
{
    

    for (int i = 0; i < numExpenses; i++)
    {
        delete[] expenses[i];
    }
    delete[] expenses;

    for (int i = 0; i < numRevenues; i++)
    {
        delete[] revenues[i];
    }
    delete[] revenues;


}

int BankAccount::getAccountNumber()const
{
    return AccountNumber;
 }
void BankAccount::setAccountNumber(int A)
{
    AccountNumber = A;
}
int BankAccount::getBalance()const
{
    return Balance;
}
void BankAccount::setBalance(int B)
{
    if (B > 0)
    {
        cout << "The balalnce of the account is positive" << endl;
        Balance = B;
    }
    else
    {
        cout << "The balance of the account is negative" << endl;
        Balance = B;
    }
}



int BankAccount::getNumExpenses()const
{
    return numExpenses;
}

void BankAccount::setNumExpenses(int num)
{
    numExpenses = num;
}

int BankAccount::getNumRevenues()const
{
    return numRevenues;
}

void BankAccount::setNumRevenues(int num)
{
    numRevenues = num;
}

int BankAccount::getSaving()const
{
    return Saving;
}

void BankAccount::setSaving(int saving)
{
    Saving = saving;
}

void BankAccount::addExpense(const Expenses& type)
{
    if (numExpenses == maxExpenses) {

        maxExpenses*=  2;
        Expenses** newExpenses = new Expenses * [maxExpenses];


        for (int i = 0; i < numRevenues; i++) {
            newExpenses[i] = expenses[i];
        }
        delete[] expenses;
        expenses = newExpenses;
        
    }
    
    expenses[numExpenses] = type.clone();
        cout << expenses[numExpenses]->getName() << endl;
        cout << expenses[numExpenses]->getExpenditure() << endl;
        numExpenses++;
    
}

void BankAccount::addRevenues(const Revenues& type)
{
    if (numRevenues == maxRevenues)
    {
         maxRevenues*= 2;
        Revenues** newRevenues = new Revenues * [maxRevenues];

        for (int i = 0; i < maxRevenues; i++)
        {
            newRevenues[i] = revenues[i];
        }

        delete[] revenues;
        revenues = newRevenues;
    
    }
    revenues[numRevenues] = type.clone();
    cout << revenues[numRevenues]->getName() << endl;
    cout << revenues[numRevenues]->getSum() << endl;
    numRevenues++;
    
}	

void BankAccount::print()const
{
    cout << "The account number is:" << AccountNumber << endl;
    cout << "The maximum of the revenues is:" << maxRevenues << endl;
    cout << "The maximun of the expenses is:" << maxExpenses << endl;
    cout << "The balance of the account holder is:" << Balance << endl;

}


int  BankAccount::calculate()
{
    int totalRevenues = 0;
    int totalExpenses = 0;
    int saving;

    for (int i = 0; i < numRevenues; i++)
    {
        totalRevenues += revenues[i]->getSum();

    }
    for (int i = 0; i < numExpenses; i++)
    {

        totalExpenses += expenses[i]->getExpenditure();

    }
    saving = totalRevenues - totalExpenses;

    setSaving(saving);

    return saving;
}

bool  BankAccount::cheakSaving()
{
    int saving = calculate();

    if (saving > 0)
    {
        cout << "Congratulations! You managed to save $" << saving << " this month." << endl;
        return true;
    }
    else if (saving == 0)
    {
        cout << "You broke even this month. Your savings are $0." << endl;
        return true;
    }
    else
        return false;
    cout << "You spent more than you earned this month. Your deficit is $" << -saving << "." << endl;
}



ostream& operator<<(ostream& os, const BankAccount& num)
{
    os << num.AccountNumber << endl;
    os << num.Balance << endl;
    
    os << num.maxExpenses << endl;
    os << num.maxRevenues << endl;
    os << num.numExpenses << endl;
    os << num.numRevenues << endl;

    int numExpense;
    cout << "Enter the num of the expenses:" << endl;
    cin >> numExpense;
    for (int i = 0; i < numExpense; i++)
    {
        os << num.expenses[i]->getExpenditure() << endl;
    }

    int numRevenues;
    cout << "Enter the num of the revenues:" << endl;
    cin >> numRevenues;
    for (int i = 0; i < numRevenues; i++)
    {
        os << num.revenues[i]->getSum() << endl;
    }

    return os;
}

istream& operator>>(istream& is, BankAccount& num)
{
    cout << "Enter the account number:" << endl;
    is >> num.AccountNumber;

    cout << "Enter the num of the balance:" << endl;
    is >> num.Balance;

    is >> num.numExpenses;
    is >> num.numRevenues;

    cout << "Enter the number of expenses:" << endl;
    is >> num.maxExpenses;
    num.expenses = new Expenses * [num.maxExpenses];

    cout << "Enter your number of revenues:" << endl;
    is >> num.maxRevenues;
    num.revenues = new Revenues * [num.maxRevenues];

    return is;
}

bool BankAccount::operator>(const BankAccount& num) const
{
    return(AccountNumber > num.AccountNumber) && (Balance > num.Balance) && (maxExpenses > num.maxExpenses) && (maxRevenues > num.maxRevenues) && (numExpenses > num.numExpenses) && (numRevenues > num.numRevenues);
}
bool BankAccount::operator<(const BankAccount& num)const
{
    return(AccountNumber < num.AccountNumber) && (Balance < num.Balance) && (maxExpenses < num.maxExpenses) && (maxRevenues < num.maxRevenues) && (numExpenses < num.numExpenses) && (numRevenues < num.numRevenues);
}

const BankAccount& BankAccount:: operator=(const BankAccount& other)
{
    if (this == &other)
    {
        return *this;
    }

    AccountNumber = other.AccountNumber;
    Balance = other.Balance;

    numExpenses = other.numExpenses;
    numRevenues = other.numRevenues;
    maxExpenses = other.maxExpenses;
    maxRevenues = other.maxRevenues;
    
    int numExpense;
    cout << "Enter the num of the expenses:" << endl;
    cin >> numExpense;
    for (int i = 0; i < numExpense; i++)
    {
        delete[] expenses[i];
    }

    
    for (int i = 0; i < numExpense; i++)
    {
        expenses[i] = new Expenses(other.expenses[i]->getExpenditure(),other.expenses[i]->getName());
    }


    int numRevenues;
    cout << "Enter the num of the revenues:" << endl;
    cin >> numRevenues;
    for (int i = 0; i < numRevenues; i++)
    {
        delete[] revenues[i];
    }

    for (int i = 0; i < numRevenues; i++)
    {
        revenues[i] = new Revenues(other.revenues[i]->getSum(),other.revenues[i]->getName());
    }

    return *this;

}
bool BankAccount::operator==(const BankAccount& other)const
{
    return AccountNumber == other.AccountNumber &&
        Balance == other.Balance &&
        maxExpenses == other.maxExpenses &&
        maxRevenues == other.maxRevenues &&
        numExpenses == other.numExpenses &&
        numRevenues == other.numRevenues;
}
BankAccount BankAccount::operator*()
{
    AccountNumber = AccountNumber * 2;
    Balance = Balance * 2;
    maxExpenses = maxExpenses * 2;
    maxRevenues = maxRevenues * 2;
    numExpenses = maxExpenses * 2;
    numRevenues = numRevenues * 2;

    return *this;
}

BankAccount& BankAccount::operator++()
{
    AccountNumber++;
    Balance++;
    maxExpenses++;
    maxRevenues++;
    numExpenses++;
    numRevenues++;

    return *this;
}
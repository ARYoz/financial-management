#pragma warning(disable: 4996)
#include "OneTimeExpense.h"
#include "Expenses.h"
#include <iostream>
using namespace std;



OneTimeExpense::~OneTimeExpense()
{

	delete[] Name;
}

bool OneTimeExpense::IsOnetimeExpenses()const
{
	int num;
	cout << "How many times did this expense happen this month?" << endl;
	cin >> num;
	if (num > 1)
	{
		return false;
	}
	else
	{
		return true;
	}
}


void OneTimeExpense::PrintDetaiils()const
{
	cout << "The details of the expense are:" << endl;
	cout << "The name of the expense is:" << Name << endl;
	cout << "The date on which the expenditure was made:" << D << endl;
	cout << "The sum of this expenxe is" << Expenditure << endl;
}

Date OneTimeExpense::getDate()const
{
	return D;
}


const char* OneTimeExpense::getName()const
{
	return Name;
}

void OneTimeExpense::setName(char* name)
{
	if (Name != NULL)
	{
		delete[] Name;
	}

	if (name != NULL)
	{
		int length = strlen(name) + 1;
		Name = new char[length];
		strcpy(Name, name);
	}
	else
		Name = NULL;
}

int OneTimeExpense::calculateExpense()
{
	int totalExpenses = 0;
	int expense[50];
	int num;
	cout << "How many types of such expenses do you have?" << endl;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		int sum;
		cout << "What is the cost of this expense?" << endl;
		cin >> sum;
		setExpenditure(sum);

		expense[i] = getExpenditure();
		totalExpenses += expense[i];
	}

	return totalExpenses;

}

ostream& operator<<(ostream& os, const OneTimeExpense& expense)
{
	os << expense.Name << endl;
	os << expense.D << endl;

	return os;
}

istream& operator>>(istream& is, OneTimeExpense& expense)
{
	const int stringSize = 50;
	char string[stringSize];

	cout << "Enter the details of the expense:" << endl;

	cout << "Enter the Name: " << endl;
	is.getline(string, stringSize);
	expense.setName(string);

	cout << "Enter the Date:" << endl;

	is >> expense.D;


	return is;

}

const OneTimeExpense& OneTimeExpense::operator=(const OneTimeExpense& expense)
{
	if (this == &expense)
	{
		return *this;
	}

	delete[] Name;

	Name = new char[strlen(expense.Name) + 1];
	strcpy(Name, expense.Name);


	D = expense.D;
	
	return *this;
}


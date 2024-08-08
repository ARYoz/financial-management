#include "FixedExpense.h"
#include <iostream>
using namespace std;



FixedExpense::~FixedExpense()
{
	delete[] Name;
}

void FixedExpense::PrintDetaiils()const
{
	cout << "The name of this  expense is:" << Name << endl;
	cout << "The month of this expense is:" << Month << endl;
	cout << "The cost of this expense is:" << Expenditure << endl;
}

int FixedExpense::getMonth()const
{
	return Month;
}

void FixedExpense::setMonth(int month)
{
	Month = month;
}

const char* FixedExpense::getName()const
{
	return Name;
}

void FixedExpense::setName( char* name)
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
bool FixedExpense::getExpense()const
{
	return Expense;
}

void  FixedExpense::setExpense(bool expense)
{
	Expense = expense;
}

int FixedExpense::calculateExpense()
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
ostream& operator<<(ostream& os, const FixedExpense& expense)
{
	os << expense.Name << endl;
	os << expense.Month << endl;
	os << expense.Expenditure << endl;
	os << expense.Expense << endl;

	return os;
}

istream& operator>>(istream& is, FixedExpense& expense)
{
	const int stringSize = 50;
	char string[stringSize];

	cout << "Enter the Name:" << endl;
	is.getline(string, stringSize);
	expense.setName(string);

	cout << "Enter the month:" << endl;
	is >> expense.Month;

	cout << "Enter true if the expense is fixed and false if is not fixed:" << endl;
	is >> expense.Expense;

	cout << "Enter the cost of the expense:" << endl;
	is >> expense.Expenditure;

	return is;
}

const FixedExpense& FixedExpense::operator=(const FixedExpense& expense)
{
	if (this == &expense)
	{
		return *this;
	}

	delete[] Name;

	Name = new char[strlen(expense.Name) + 1];
	strcpy(Name, expense.Name);

	Month = expense.Month;

	Expense = expense.Expense;
 }


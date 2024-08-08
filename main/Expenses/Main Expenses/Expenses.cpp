#include "Expenses.h"
#include <iostream>
using namespace std;


Expenses::Expenses(const Expenses& other)
{
	Name = new char[strlen(other.Name) + 1];
	strcpy(Name, other.Name);

	Expenditure = other.Expenditure;
}

Expenses::~Expenses()
{
	cout << "d'tor" << Expenditure << endl;
	delete[] Name;
}

int Expenses::getExpenditure() const
{
	return Expenditure;
}

void Expenses::setExpenditure(int expense)
{
	Expenditure = expense;
}

const char* Expenses:: getName()const
{
	return Name;
}

void Expenses::setName(char* name)
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
	{
		Name = NULL;
	}
}
const Expenses& Expenses::operator=(const Expenses& sum)
{
	if (this == &sum)
	{
		return *this;
	}

	delete[] Name;

	Expenditure = sum.Expenditure;
	Name = new char[strlen(sum.Name) + 1];
	strcpy(Name, sum.Name);


	return *this;
}
void Expenses::PrintDetaiils()const
{
	cout << "The cost of the expense is:" << Expenditure;
	cout << "The name of the expenses is" << Name;
}

bool Expenses::IsOnetimeExpenses()const
{
	int num = 0;

	cout << "if the expense is only one time cin 1 else cin 0:" << endl;
	cin >> num;

	if (num == 1)
	{
		return true;
		cout << "this is one time expense" << endl;
	}
	else
	{

		return false;
		cout << "this is not a one time expense" << endl;
	}


}

bool Expenses::operator>(const Expenses& num)
{
	return Expenditure > num.Expenditure;
}

bool Expenses::operator<(const Expenses& num)
{
	return Expenditure < num.Expenditure;
}

ostream& operator<<(ostream& os, const Expenses& expense)
{
	os << expense.Expenditure << endl;
	os << expense.Name << endl;
	return os;
}

istream& operator>>(istream& is, Expenses& expense)
{

	const int stringSize = 50;
	char string[stringSize];

	cout << "Enter the name of the expense:" << endl;
	is.getline(string, stringSize);
	expense.setName(string);
	cout << "Enter the cost of the expense:" << endl;
	is >> expense.Expenditure;

	return is;
}


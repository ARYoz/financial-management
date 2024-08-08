#include "Revenues.h"
#include <iostream>
using namespace std;


Revenues::~Revenues()
{
	delete[] Name;
}
Revenues::Revenues(const Revenues& other)
{
	Name = new char[strlen(other.Name) + 1];
	strcpy(Name, other.Name);

	Sum = other.Sum;
}
int Revenues::getSum() const
{
	return Sum;
}

void Revenues::setSum(int sum)
{
	Sum = sum;
}

const char* Revenues::getName()const
{
	return Name;
}

void Revenues::setName(const char* name)
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
const Revenues& Revenues::operator=(const Revenues& sum)
{
	if (this == &sum)
	{
		return *this;
	}
	delete[] Name;

	Sum = sum.Sum;

	Name = new char[strlen(sum.Name) + 1];
	strcpy(Name, sum.Name);
}
bool Revenues::operator>(const Revenues& num)
{
	return Sum > num.Sum;
}

bool Revenues::operator<(const Revenues& num)
{
	return Sum < num.Sum;
}

ostream& operator<<(ostream& os, const Revenues& sum)
{
	os << sum.Sum;
	os << sum.Name;
	return os;
}
istream& operator>>(istream& is, Revenues& sum)
{
	const int stringSize = 50;
	char string[stringSize];

	cout << "Enter your first Name:" << endl;
	is.getline(string, stringSize);
	sum.setName(string);

	is >> sum.Sum;

	return is;
}

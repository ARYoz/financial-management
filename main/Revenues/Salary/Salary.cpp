#include "Salary.h"
#include <iostream>
using namespace std;

int Salary::getFather() const
{
	return FatherSalary;
}

int Salary::getMother() const
{
	return MotherSalary;
}

void Salary::setFather(int father)
{
	FatherSalary = father;
}

void Salary::setMother(int mother)
{
	MotherSalary = mother;
}

void Salary::print() const
{
	cout << "The salary of the Father is:" << FatherSalary << endl;
	cout << "The salary of the Mother is:" << MotherSalary << endl;
	cout << "The salary of the boths is:" << FatherSalary + MotherSalary << endl;
}

int Salary::calculateIncome()
{
	return (FatherSalary + MotherSalary);
}



ostream& operator<<(ostream& os, const Salary& salary)
{
	os << salary.FatherSalary << endl;
	os << salary.MotherSalary << endl;

	return os;
}

istream& operator>>(istream& is, Salary& salary)
{
	is >> salary.FatherSalary;
	is >> salary.MotherSalary;

	return is;
}

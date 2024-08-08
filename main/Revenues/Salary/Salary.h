#include <iostream>
#include "Revenues.h"
using namespace std;
#pragma once
class Salary:public Revenues
{
protected:
	int FatherSalary;
	int MotherSalary;

public:

	Salary(int F, int M,int sum,const char* name) :Revenues(sum,name)
	{
		FatherSalary = F;
		MotherSalary = M;
		
	}// constractor
	int getFather()const;
	int getMother()const;
	void setFather(int father);
	void setMother(int mother);
	void print()const;
	int calculateIncome()override; // the sum of the two salaries
	friend ostream& operator<<(ostream& os, const Salary& in); // cout
	friend istream& operator>>(istream& is, Salary& r); // cin
	Revenues* clone()const override { return new Salary(*this); }
	
};


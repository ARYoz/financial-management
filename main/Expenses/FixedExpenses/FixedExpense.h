#pragma warning(disable: 4996)
#include <iostream>
#include "Expenses.h"
using namespace std;
#pragma once
class FixedExpense:public Expenses
{
protected:
	int Month; //the month of the expense
	char* Name;//the name of the expense
	bool Expense;// if the expense is fixed or one time
public:
	FixedExpense(int month, const char* name, bool expense,int sum,const char* name2) :Expenses(sum,name2)
	{
		Month = month;
		Name = new char[strlen(name) + 1];
		strcpy(Name, name);
		Expense = expense;
	}//constractor
	FixedExpense(const FixedExpense& other):Expenses(other)
	{
		Name = new char[strlen(other.Name) + 1];
		strcpy(Name, other.Name);
	}// copy constractor
	~FixedExpense()override; // destractor
	void PrintDetaiils()const override; // here we print the name of the expenses and how much did it cost
	int getMonth()const;
	void setMonth(int month);
	const char* getName()const;
	void setName(char* name);
	bool getExpense()const;
	void setExpense(bool expense);
	int calculateExpense()override;
	friend ostream& operator<<(ostream& os, const FixedExpense& expense); // cout
	friend istream& operator>>(istream& is, FixedExpense& expense); // cin
	const FixedExpense& operator=(const FixedExpense& num);
	Expenses* clone()const override { return new FixedExpense(*this); }
	

};


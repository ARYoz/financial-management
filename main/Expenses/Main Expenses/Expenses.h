#pragma warning(disable: 4996)
#include <iostream>
using namespace std;
#pragma once
class Expenses
{
protected:

	int Expenditure;  //the sum of the expense
	char* Name;
	
public:
	Expenses(int expense, const char* name) {
		Expenditure = expense;
		Name = new char[strlen(name) + 1];
		strcpy(Name, name);
	} // constractor
	Expenses(const Expenses& other);//copy constractor
	virtual ~Expenses(); //distractor
	int getExpenditure()const;
	void setExpenditure(int expense);
	const char* getName()const;
	void setName(char* name);
	virtual bool IsOnetimeExpenses()const;
	virtual void PrintDetaiils()const;
	virtual int calculateExpense()
	{
		return 0;
	}
	const Expenses& operator=(const Expenses& sum);
	bool operator>(const Expenses& num);
	bool operator<(const Expenses& num);
	friend ostream& operator<<(ostream& os, const Expenses& expense); // cout
	friend istream& operator>>(istream& is, Expenses& expense); // cin
	virtual Expenses* clone()const 
	{
		return new Expenses(*this);
	}
	
};


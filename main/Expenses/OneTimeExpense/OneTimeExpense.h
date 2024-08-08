#pragma warning(disable: 4996)
#include <iostream>
#include "Expenses.h"
#include "Date.h"
using namespace std;
#pragma once


class OneTimeExpense :public Expenses
{
protected:
	char* Name; // the name of the expense
	Date  D;// the date in the month where the expense occurred
	
public:
	OneTimeExpense(const Date& day, const char* name, int expense,const char* name2) :D(day),Expenses(expense,name2)
	{
			Name = new char[strlen(name) + 1];
			strcpy(Name, name);
	}
	OneTimeExpense(const OneTimeExpense& other):Expenses(other),D(other.D)
	{
		Name = new char[strlen(other.Name) + 1];
		strcpy(Name, other.Name);
	}//copy constractor
		~OneTimeExpense()override; // destractor
		bool IsOnetimeExpenses()const override; //cheaking if the expense in only for one time and no more
		void PrintDetaiils()const override; // here we print the name of the expenses and how much did it cost
		Date getDate()const;
		const char* getName()const;
		void setName(char* name);
		int calculateExpense()override;
		friend ostream& operator<<(ostream& os, const OneTimeExpense& expense); // cout
		friend istream& operator>>(istream& is, OneTimeExpense& expense); // cin
		const OneTimeExpense& operator=(const OneTimeExpense& expense);
		Expenses* clone()const override { return new OneTimeExpense(*this); }
};

#include <iostream>
#include "Revenues.h"
#include "Expenses.h"
using namespace std;
#pragma once
class BankAccount
{
private:
	int AccountNumber;
	int Balance;
	int Saving = 0;
	int maxExpenses;
	int maxRevenues;
	int numExpenses = 0;
	int numRevenues = 0;
	Expenses **expenses;//array expenses
	Revenues **revenues;//array reveues
public:
	BankAccount(int accountNumber = 0, int balance = 0, int saving = 0)
	{
		AccountNumber = accountNumber;
		Balance = balance;
		Saving = saving;
		maxExpenses = 2;
		maxRevenues = 2;
		expenses = new Expenses * [maxExpenses];
		revenues = new Revenues * [maxRevenues];

		for (int i = 0; i < numExpenses; i++)
		{
			expenses[i] = nullptr;
		}
		for (int i = 0; i < numRevenues; i++)
		{
			revenues[i] = nullptr;
		}
	}
	~BankAccount();
    int getAccountNumber()const;
	void setAccountNumber(int A);
	int getBalance()const;
	void setBalance(int B);
	int getNumRevenues()const;
	void setNumRevenues(int num);
	int getNumExpenses()const;
	void setNumExpenses(int num);
	int getSaving()const;
	void setSaving(int saving);
	void addExpense(const Expenses& type);
	void addRevenues(const Revenues& type);
	void print()const;
	int calculate();//calculating all the revenues - all the expense
	bool cheakSaving();// cheaking if the person have a  good financial management or not?
	friend ostream& operator<<(ostream& os, const BankAccount& num); // cout
	friend istream& operator>>(istream& is, BankAccount& num); // cin
	const BankAccount& operator=(const BankAccount& num);
	bool operator>(const BankAccount& num)const;
	bool operator<(const BankAccount& num)const;
	bool operator==(const BankAccount& other) const;
	BankAccount operator*();
	BankAccount& operator++();

};


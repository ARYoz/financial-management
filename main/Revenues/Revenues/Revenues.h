#pragma warning(disable: 4996)
#include <iostream>
using namespace std;
#pragma once
class Revenues
{
protected:
	int Sum;
	char* Name;
public:
	Revenues(int sum, const char* name)
	{
		Sum = sum;
		Name = new char[strlen(name) + 1];
		strcpy(Name, name);
	}// constractor
	virtual ~Revenues();
	Revenues(const Revenues& other);//copy constractor
	int getSum()const;
	void setSum(int sum);
	const char* getName()const;
	void setName(const char* name);
	virtual int calculateIncome()
	{
		return 0;
	}
	const Revenues& operator=(const Revenues& sum);
	bool operator>(const Revenues& num);
	bool operator<(const Revenues& num);
	friend ostream& operator<<(ostream& os, const Revenues& sum); // cout
	friend istream& operator>>(istream& is, Revenues& sum); // cin
	virtual Revenues* clone() const
	{
		return new Revenues(*this);
	}
};


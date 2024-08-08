#include <iostream>
#include "Revenues.h"
using namespace std;
#pragma once
class Unofficialincome:public Revenues
{

public:
	enum  unofficialincome { Inheritance = 0, Lotto, Scholarship };
private:
	unofficialincome Type;
public:
	Unofficialincome(const unofficialincome type,int sum,const char* name):Revenues(sum,name),Type(type){}// constractor
	unofficialincome getType()const;
	void setType(unofficialincome type);
	void print()const;
	int calculateIncome()override; // calculate the sum of the profit
	friend ostream& operator<<(ostream& os, const Unofficialincome& in); // cout
	friend istream& operator>>(istream& is,  Unofficialincome& r); // cin
	Revenues* clone()const override { return new Unofficialincome(*this); }

};


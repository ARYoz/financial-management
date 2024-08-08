#include <iostream>
#include "Revenues.h"
using namespace std;
#pragma once
class SocialSecurity:public Revenues
{
private:
	double DisabilityPercentageFather;
	double DisabilityPercentageMother;

public:
	SocialSecurity(double Father, double Mother, int sum, const char* name) :Revenues(sum, name)
	{
		DisabilityPercentageFather = Father;
		DisabilityPercentageMother = Mother;
	}
	double getFather()const;
	double getMother()const;
	void setFather(double father);
	void setMother(double mother);
	int calculateIncome() override;  // calculate the sum of this Revenues
	void print()const; // print the sum that get in
	const SocialSecurity& operator=(const SocialSecurity& num);
	friend ostream& operator<<(ostream& os, const SocialSecurity& sum); // cout
	friend istream& operator>>(istream& is, SocialSecurity& sum); // cin
	virtual Revenues* clone()const override { return new SocialSecurity(*this);}
};


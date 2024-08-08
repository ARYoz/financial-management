#include "SocialSecurity.h"
#include "Revenues.h"
#include <iostream>
using namespace std;


double SocialSecurity::getFather()const
{
	return DisabilityPercentageFather;
}
double SocialSecurity::getMother()const
{
	return DisabilityPercentageMother;
}
void SocialSecurity::setFather(double fahter)
{
	if (fahter > 1 || fahter < 0)
	{
		cout << "The number should be between 0 and 1" << endl;
	}
	else
	{
		DisabilityPercentageFather = fahter;
	}
}
void SocialSecurity::setMother(double mother)
{
	if (mother > 1 || mother < 0)
	{
		cout << "The number should be between 0 and 1" << endl;
	}
	else
	{
		DisabilityPercentageMother = mother;
	}
}

int SocialSecurity::calculateIncome()
{
	
	return (DisabilityPercentageFather + DisabilityPercentageMother);

}

void  SocialSecurity::print()const
{
	double sum = DisabilityPercentageFather + DisabilityPercentageMother;
	cout << "the Disability Percentage Father is:" << DisabilityPercentageFather << endl;
	cout << "the Disability Percentage Mother is:" << DisabilityPercentageMother << endl;
	cout << "the Disability Percentage of the bots is:" << sum << endl;

}
const SocialSecurity& SocialSecurity::operator=(const SocialSecurity& sum)
{
	if (this != &sum)
	{
		DisabilityPercentageFather = sum.DisabilityPercentageFather;
		DisabilityPercentageMother = sum.DisabilityPercentageMother;
	}
	return *this;
}
ostream& operator<<(ostream& os, const SocialSecurity& sum)
{
	os << sum.DisabilityPercentageFather << endl;
	os << sum.DisabilityPercentageMother << endl;

	return os;
}
istream& operator>>(istream& is, SocialSecurity& sum)
{
	cout << "Enter the father's and mother's disability percentages:" << endl;
	is >> sum.DisabilityPercentageFather;
	is >> sum.DisabilityPercentageMother;
	return is;
}
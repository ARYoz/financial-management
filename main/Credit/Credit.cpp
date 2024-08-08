#pragma warning(disable: 4996)
#include "Credit.h"
#include <iostream>
using namespace std;


void Credit::setCardNumber(int number)
{
	CardNumber = number;
}
int Credit::getCardNumber()const
{
	return CardNumber;
}

void Credit::setCellingAmount(int number)
{
	CellingAmount = number;
}
int Credit::getCellingAmount()const
{
	return CellingAmount;
}

Credit* Credit::getPartner()const
{
	return Partner;
}

void Credit::setPartner(const Credit* partner)
{

	Partner = partner->Partner;
}

void Credit::print()const
{
	cout << CardNumber << endl;
	cout << CellingAmount << endl;
	if (Partner != nullptr)
	{
		cout << "Partner Details:" << endl;
		Partner->getCardNumber();
		Partner->getCellingAmount();
	}
	else
	{
		cout << "No partner" << endl;
	}
	
}


bool Credit::operator<(const Credit& num)const
{
	return ((CellingAmount < num.CellingAmount) &&( CardNumber < num.CardNumber));
}

bool Credit::operator>(const Credit& num)const
{
	return((CellingAmount > num.CellingAmount) && (CardNumber > num.CardNumber));
}


bool Credit::CheakCard()const
{
	
	if (CardNumber < 10000000000000000 || CardNumber > 99999999999999999)
	{
		
		cout << "The card number is not right" << endl;
		return false;
	}
	else
	{
		cout << "The card number is right" << endl;
		return true;
	}
}



ostream& operator<<(ostream& os, const Credit& num)
{

	os << num.CardNumber << endl;
	os << num.CellingAmount << endl;

	return os;
}

istream& operator>>(istream& is, Credit& num)
{
	is >> num.CardNumber;
	is >> num.CellingAmount;
	return is;
}

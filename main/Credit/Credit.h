#pragma warning(disable: 4996)
#include <iostream>
using namespace std;
#pragma once
class Credit
{
protected:
    int CardNumber;
	int CellingAmount;
	Credit* Partner = NULL;
public:
	Credit( int cardNumber, int cellingAmount,Credit* partner=nullptr)
	{
		CardNumber = cardNumber;
		CellingAmount = cellingAmount;
	}
	void setCardNumber(int number);
	int getCardNumber()const;
	void setCellingAmount(int number);
	int getCellingAmount()const;
	Credit* getPartner()const;
	void setPartner(const Credit* partner);
	void print()const;
	bool operator>(const Credit& other)const;
	bool operator<(const Credit& other)const;
	bool CheakCard()const; // here we cheak if the number card is proper
	friend ostream& operator<<(ostream& os, const Credit& num); // cout
	friend istream& operator>>(istream& is,  Credit& num); // cin

};


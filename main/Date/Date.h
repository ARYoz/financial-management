#include <iostream>
using namespace std;
#pragma once
class Date
{
private:
	int Day;
	int Month;
	int Year;
public:
	Date(int d, int m, int y);//constractor
	bool setday(int d);
	bool setmonth(int m);
	bool setyear(int y);
	int getday()const;
	int getmonth()const;
	int getyear()const;
	void print()const;
	friend ostream& operator<<(ostream& os, const Date& date); // cout
	friend istream& operator>>(istream& is, Date& date); // cin

};
#include "Date.h"
#include <iostream>
using namespace std;
#include<iostream>
using namespace std;

Date::Date(int d, int m, int y)
{
	setday(d);
	setmonth(m);
	setyear(y);
}

bool Date::setday(int d)
{
	if (d < 1 || d > 31)
	{
		cout << "The maximum number of days that can be in a month is 31 and the minimum is 1" << endl;
		return false;
	}
	else
	{
		Day = d;
		return true;
	}
}

bool Date::setmonth(int m)
{
	if (m < 1 || m > 12)
	{
		cout << "The maximum moths that we have in a year is 12 and minimum 1" << endl;
		return false;
	}
	else
	{
		Month = m;
		return true;
	}
}

bool Date::setyear(int y)
{
	if (y < 1000 || y >= 10000)
	{
		cout << "you must have 4 digit in the number of the year" << endl;
		return false;
	}
	else
	{
		Year = y;
		return true;
	}
}

int Date::getday() const
{
	return Day;
}

int Date::getmonth() const
{
	return Month;
}

int Date::getyear() const
{
	return Year;
}



void Date::print() const
{
	cout << Day << "/" << Month << "/" << Year << endl;
}

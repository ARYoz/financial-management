#pragma warning(disable: 4996)
#include <iostream>
#include "Revenues.h"
using namespace std;
#pragma once
class ApartmentRental:public Revenues
{
private:
	char* Name; // the name of the Tenant
	int TimeContrat; //How many months is the contract?
	int Maintenance;//Average annual maintenance cost
	
	
	
public:
	ApartmentRental(const char* name, int time,int maintenace,const char* name2,int sum):Revenues(sum,name2)
	{
		Name = new char[strlen(name) + 1];
		strcpy(Name, name);
		TimeContrat = time;
		Maintenance = maintenace;

	} 
	ApartmentRental(const ApartmentRental& other):Revenues(other)
	{
		Name = new char[strlen(other.Name) + 1];
		strcpy(Name, other.Name);
		TimeContrat = other.TimeContrat;
		Maintenance = other.Maintenance;
	}//copy constractor
	~ApartmentRental(); //destractor
	const char* getName()const;
	void setName( char* name);
	int getMaintenance()const;
	void setMaintenance(int maintenace);
	int getTimeContrat()const;
	void setTimeContrat(int time);
	int calculateIncome()override; //calculate the neto profit per month
	void print()const; // print the neto profit
	const ApartmentRental& operator=(const ApartmentRental& num);
	friend ostream& operator<<(ostream& os, const ApartmentRental& in); // cout
	friend istream& operator>>(istream& is, ApartmentRental& r); // cin
	Revenues* clone()const override { return new ApartmentRental(*this); } 
};


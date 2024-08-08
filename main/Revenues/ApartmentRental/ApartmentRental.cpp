#pragma warning(disable: 4996)
#include "ApartmentRental.h"
#include <iostream>
using namespace std;



ApartmentRental :: ~ApartmentRental()
{
	delete[] Name;

}

const char* ApartmentRental:: getName()const
{
	return Name;
}

void ApartmentRental::setName(char* name)
{
	if (Name != NULL)
	{
		delete[] Name;
	}

	if (name != NULL)
	{
		int length = strlen(name) + 1;
		Name = new char[length];
		strcpy(Name, name);
	}
}

int ApartmentRental::getMaintenance()const
{
	return Maintenance;
}

void  ApartmentRental::setMaintenance(int maintenace)
{
	Maintenance = maintenace;
}

int ApartmentRental::getTimeContrat()const
{
	return TimeContrat;
}
void ApartmentRental::setTimeContrat(int time)
{
	TimeContrat = time;
}

int ApartmentRental::calculateIncome()
{
	return(Sum - Maintenance);
}



void ApartmentRental::print()const
{
	int profit = getSum() - getMaintenance();
	cout << "The neto profit of the AparmentRental is:" << profit << endl;
}

const ApartmentRental& ApartmentRental::operator=(const ApartmentRental& num)
{
	if (this == &num)
	{
		return *this;
	}

	delete[] Name;

	Name = new char[strlen(num.Name) + 1];
	strcpy(Name, num.Name);

	TimeContrat = num.TimeContrat;
	Maintenance = num.Maintenance;

	return *this;
}



istream& operator>>(istream& is, ApartmentRental& details)
{
	cout << "Enter the details of this ApartmentRental:" << endl;
	
	const int stringSize = 50;
	char string[stringSize];

	cout << "Enter Name: " << endl;
	is.getline(string, stringSize);
	details.setName(string);

	cout << "Enter the cost per month:" << endl;
	is >> details.Sum;

	cout << "Enter the time contrat:" << endl;
	is >> details.TimeContrat;

	cout << "Enter the  maintenance of the apartment per month:" << endl;
	is >> details.Maintenance;

	return is;

}


ostream& operator<<(ostream& os, const ApartmentRental& details)
{
	os << details.Name << endl;
	os << details.Sum << endl;
	os << details.Maintenance << endl;
	os << details.TimeContrat << endl;

	return os;
}
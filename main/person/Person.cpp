#pragma warning(disable: 4996)
#include "Person.h"
#include "Date.h"
#include<iostream>
using namespace std;




Person::~Person()
{
	
	delete[] firstName;
	delete[] lastName;
	delete[] Proffesion;
}

 const char* Person::getName()const
{
	return firstName;
}

void Person::setFirstName(char * name)
{
	if (firstName != NULL)
	{
		delete[] firstName;
	}

	if (name != NULL)
	{
		int length = strlen(name) + 1;
		firstName = new char[length];
		strcpy(firstName, name);
	}
	else
	{
		firstName = NULL;
	}

}

const char* Person::getLastName() const
{
	return lastName;
}

void Person::setLastName(char* name)
{
	if (lastName != NULL)
	{
		delete[] lastName;
	}

	if (name != NULL)
	{
		int length = strlen(name) + 1;
		lastName = new char[length];
		strcpy(lastName, name);
	}
	else
	{
		lastName = NULL;
	}

}

int const Person::getId()
{
	return ID;
}

bool Person::setId(int id)
{
	if (id < 10000000 || id >1000000000)
	{
		cout << "ERROR in the numbre of the ID" << endl;
		return false;
	}
	else
		ID = id;
	return true;

	
}
const Date& Person::getDateBirth()const
{
	return D;
}

const char* Person::getProffesion()const
{
	return Proffesion;
}

void Person::setProffesion(char * proffesion)
{
	if (Proffesion != NULL)
	{
		delete[] Proffesion;
	}
	if (proffesion != NULL)
	{
		int length = strlen(proffesion) + 1;
		Proffesion = new char[length];
		strcpy(Proffesion, proffesion);
	}
	else
		Proffesion = NULL;
}

Person* Person::getPartner()const
{
	return Partner;
}

void Person::setPartner( const Person* partner)
{

	Partner = partner->Partner;
}


void Person::print() const
{
	cout << firstName << " " << lastName << endl;
	cout << ID << endl;
	cout << D << endl;
	cout << Proffesion << endl;
	if (Partner != nullptr)
	{
		cout << "Partner Details:" << endl;
		cout << Partner->getName() << endl;
		cout << Partner->getId() << endl;
		cout << Partner->getDateBirth() << endl;
		cout << Partner->getProffesion() << endl;
	}
	else
	{
		cout << "Dont have a Partner" << endl;
	}

}

const Person& Person::operator=(const Person& person)
{
	if (this == &person)
	{
		return *this;
	}

	delete[] firstName;
	delete[] lastName;
	delete[] Proffesion;

	firstName = new char[strlen(person.firstName) + 1];
	strcpy(firstName, person.firstName);

	lastName = new char[strlen(person.lastName) + 1];
	strcpy(lastName, person.lastName);
	ID = person.ID;
	D = person.D;

	Proffesion = new char[strlen(person.Proffesion) + 1];
	strcpy(Proffesion, person.Proffesion);

	Partner = person.Partner;

	return *this;
}


ostream& operator<<(ostream& os, const Date& date)
{
	os << date.Day << "/" << date.Month << "/" << date.Year << endl;
	return os;
}

istream& operator>>(istream& is, Date& date)
{
	cout << "Enter Date (DD/MM/YYYY): ";
	char slash;
	is >> date.Day >> slash >> date.Month >> slash >> date.Year;
	return is;
}

ostream& operator<<(ostream& os, const Person& person)
{
	os << person.firstName << endl;
	os << person.lastName << endl;
	os << person.D << endl;
	os << person.ID << endl;
	os << person.Proffesion << endl;
	os << person.Partner << endl;

	return os;
}

istream& operator>>(istream& is, Person& person)
{
	const int stringSize = 50;
	char string[stringSize];

	cout << "Enter your first Name:" << endl;
	is.getline(string, stringSize);
	person.setFirstName(string);

	cout << "Enter your last Name;" << endl;
	is.getline(string, stringSize);
	person.setLastName(string);

	cout << "Enter ID: ";
	is >> person.ID;

	cout << "Enter Profession: ";
	
	is.getline(string, stringSize);
	person.setProffesion(string);

	return is;
}

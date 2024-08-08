#pragma warning(disable: 4996)
#include <iostream>
#include "Date.h"
using namespace std;
#pragma once
class Person
{
protected:
	char* firstName;
	char* lastName;
	Date D; 
	int ID;
    char* Proffesion;
	Person* Partner=NULL;
	Person(const Person& other);//copy constractor
public:

	Person(const char* firstname ,const char* lastname, int id ,const Date& d, const char* proffesion, Person* partner=nullptr) :D(d){
		firstName = new char[strlen(firstname) + 1];
		strcpy(firstName, firstname);
		lastName = new char[strlen(lastname) + 1];
		strcpy(lastName, lastname);
		ID = id;
		Proffesion = new char[strlen(proffesion) + 1];
		strcpy(Proffesion, proffesion);
		if (Partner != nullptr)
		{
			partner->firstName = new char[strlen(firstname) + 1];
			strcpy(firstName, firstname);
			partner->lastName = new char[strlen(lastname) + 1];
			strcpy(lastName, lastname);
			partner->ID = id;
			partner->Proffesion = new char[strlen(proffesion) + 1];
			strcpy(Proffesion, proffesion);
		}
		else
			Partner = partner;
	}//  constractor
	~Person();// destractor
	const char* getName()const;
	void setFirstName(char* name);
	const char* getLastName()const;
	void setLastName(char*  name);
	int const getId();
	bool setId(int id);// cheakin here if the id is currect
	const Date& getDateBirth()const;
	const char* getProffesion()const;
	void setProffesion(char * proffesion);
	Person* getPartner()const;
	void setPartner(const Person* partner);
	void print()const;//the detaiils of the bots
	friend ostream& operator<<(ostream& os, const Person& in); // cout
	friend istream& operator>>(istream& is,Person& r); // cin
	const Person& operator=(const Person& person);
};

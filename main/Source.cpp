// ary oz 321918484
// The subject of the project: correct financial management

#include "Person.h"
#include "Credit.h"
#include "Expenses.h"
#include "Revenues.h"
#include "ApartmentRental.h"
#include "BankAccount.h"
#include "FixedExpense.h"
#include "OneTimeExpense.h"
#include "Salary.h"
#include "SocialSecurity.h"
#include "Unofficialincome.h"
#include "Date.h"
#include <iostream>
using namespace std;


void cardDetails()
{
 int CardNum;
 int CellingAmount;
 cout << "enter your credit details:" << endl;
 cout << "Enter the card number:" << endl;
 cin >> CardNum;
 cout << "Enter the celling amount" << endl;
 cin >> CellingAmount;
 cout << endl;
 Credit C1(CardNum, CellingAmount);
 C1.print();
}



void Persondetails(BankAccount& Bank) 
{
 int Day, Month, Year;
 int Id;
 char Firstname[50], Lastname[50], Profession[50];
 cout << "Please fill in the following details: full name, ID, date of birth and profession:" << endl;
 cout << "Enter your first name and your last name:" << endl;
 cin >> Firstname >> Lastname;
 cout << "Enter your ID:" << endl;
 cin >> Id;
 cout << "Enter the day:" << endl;
 cin >> Day;
 cout << "Enter the month:" << endl;
 cin >> Month;
 cout << "Enter the year:" << endl;
 cin >> Year;
 cout << "Enter your proffesion:" << endl;
 cin >> Profession;
 strcpy(Firstname, Firstname);
strcpy(Lastname, Lastname);
 strcpy(Profession, Profession);
 Date D1(Day, Month, Year);
 D1.print();
 cout << endl;
 Person P1(Firstname,Lastname, Id, D1, Profession);
 P1.print();
 cout << endl;
 cardDetails();


 int Num;
 cout << "are you married?" << endl;
 cout << "For yes answer choose 1 for no answer choose 0" << endl;
 cin >> Num;

if (Num == 1)
 {
	int Day, Month, Year;
	int Id;
	char PartnerFirstName[50], PartnerLastName[50], PartnerProfession[50];
	cout << "Please fill in the details for your wife/husband as well" << endl;
	cout << endl;
	cout << "Enter your partner's name:" << endl;
	cin >> PartnerFirstName >> Lastname;
	cout << "Enter your partner's profession:" << endl;
	cin >> PartnerProfession;
	cout << "Enter your partner's ID:" << endl;
	cin >> Id;
	cout << "Enter the partner's day:" << endl;
	cin >> Day;
	cout << "Enter the partner's month:" << endl;
	cin >> Month;
	cout << "Enter the partner's year:" << endl;
	cin >> Year;
	strcpy(PartnerFirstName, PartnerFirstName);
	strcpy(PartnerLastName, PartnerLastName);
	strcpy(PartnerProfession, PartnerProfession);
	Date partnerD1(Day,Month, Year);
	Person partnerP1(PartnerFirstName, PartnerLastName, Id, partnerD1, PartnerProfession);
	partnerP1.print();
	cout << endl;
	cardDetails();
	cout << endl;
 }
}


void salary(BankAccount &Bank)
{
 int Father, Mother, Sum;
 char Revenue[50];

 cout << "Enter your salary,and if you have partner cin olso" << endl;
 cout << "Enter the salary of the father:" << endl;
 cin >> Father;
 cout << "Enter the salary of the mother:" << endl;
 cin >> Mother;
 Sum = Father + Mother;
 cout << "Enter the name of this revenue:" << endl;
 cin >> Revenue;
 Salary S(Father, Mother, Sum, Revenue);
 Bank.addRevenues(S);
	
}
void ApartamentRental(BankAccount& Bank)
{
 char Name[50];
 char Revenue[50];
 int  Maintenace, Time, Sum;
 cout << "Enter the details and the amount of income from rent:" << endl;
 cout << "Enter the name of the Tenant's name" << endl;
 cin >> Name;
 cout << "Enter the time:" << endl;
 cin >> Time;
 cout << "Enter the maintenace" << endl;
 cin >> Maintenace;
 cout << "Enter the sum of this revenue" << endl;
 cin >> Sum;
 cout << "Enter the name of this revenue:" << endl;
 cin >> Revenue;
 strcpy(Name, Name);
 ApartmentRental A(Name, Time, Maintenace, Revenue, Sum);
 Bank.addRevenues(A);

}

void  socialSecurity(BankAccount& Bank)
{
	double Father, Mother;
	int Sum;
	char Revenue[50];
	cout << "Enter the SocialSecurity if you have and olso the SocialSecurity of your wifh or hasben" << endl;
	cout << "Enter the father social security:" << endl;
	cin >> Father;
	cout << "Enter the mother social security:" << endl;
	cin >> Mother;
	cout << "Enter the sum of this revenue" << endl;
	cin >> Sum;
	cout << "Enter the name of this revenue:" << endl;
	cin >> Revenue;
	SocialSecurity Social(Father, Mother, Sum, Revenue);
	Bank.addRevenues(Social);
}
void unoffisialIncome(BankAccount& Bank)
{
 char Type[50];
 int Sum;
 int Status;
 cout << "Enter the type of the unofficialincome:" << endl;
 cout << "Enter inheritance or lotto or scholarship:" << endl;
 cin >> Type;
 cout << " Enter status[0 - Inheritance,1 - Looto,2 - In a Scholarship]" << endl;
 cin >> Status;
 cout << "Enter the sum of this revenue" << endl;
 cin >> Sum;
 Unofficialincome type(Unofficialincome::unofficialincome(Status), Sum, Type);
 Bank.addRevenues(type);
}

void fixedExpense(BankAccount& Bank)
{
 char Name[50];
 int  Month, Sum=0;
 bool E;
 cout << "enter the details of the expense:" << endl;
 cout << "Enter the name of this expense:" << endl;
 cin >> Name;
 cout << "Enter the month:" << endl;
 cin >> Month;
 cout << "if the expense is fixed enter true else enter false" << endl;
 E = true;
 cout << "Enter the sum of this expense:" << endl;
 cin >> Sum;
 strcpy(Name, Name);
 FixedExpense F(Month, Name, E, Sum, Name);
 Bank.addExpense(F);
}

void oneTimeExpense(BankAccount& Bank)
{
 char Name[50];
 int Day, Month, Year, Sum=0;
 cout << "Enter the details of the Expense:" << endl;
 cout << "Enter the day:" << endl;
 cin >> Day;
 cout << "Enter the month:" << endl;
 cin >> Month;
 cout << "Enter the year:" << endl;
 cin >> Year;
 cout << "Enter the name of this expense:" << endl;
 cin >> Name;
 cout << "Enter the sum of this expense" << endl;
 cin >> Sum;
 strcpy(Name, Name);
 Date D(Day, Month, Year);
 OneTimeExpense O(D, Name, Sum, Name);
 Bank.addExpense(O);
}


void Bank_details(BankAccount& Bank)
{
 int AccountNum, Balance, SizeR = 2,Type;
 cout << "enter your Account details:" << endl;
 cout << "Enter your account number:" << endl;
 cin >> AccountNum;
 cout << "Enter your balance:" << endl;
 cin >> Balance;
 Bank.setAccountNumber(AccountNum);
 Bank.setBalance(Balance);
 cout << "How much Revenues you have?" << endl;
 cin >> SizeR;
 for (int i = 0; i < SizeR; i++)
{
	cout << "Enter the type of this revenue:" << endl;
	cout << "for salary clik 1,for apartament rental clik 2,for social security clik 3 and for unoffisial income clik 4:" << endl;
	cin >> Type;
	switch ((Type))
	{
	case 1:
	{
		salary(Bank);
		break;
	}
	case 2:
	{
		ApartamentRental(Bank);
		break;
	}
	case 3:
	{
		socialSecurity(Bank);
		break;
	}
	case 4:
	{
		unoffisialIncome(Bank);
		break;
	}
	default:
		break;
	}
}

int SizeE, Sum=0;
cout << "How much Expenses you have?" << endl;
cin >> SizeE;
for (int i = 0; i < SizeE; i++)
{
	int Type;
	cout << "Enter the type of this Expenses:" << endl;
	cout << "for fixed expense clik 1,for one time expense clik 2:" << endl;
	cin >> Type;
	switch (Type)
	{
	case 1:
	{
		fixedExpense(Bank);
		break;
	}
	case 2:
	{
		oneTimeExpense(Bank);
		break;
	}
	
	default:
		break;
	}
}
Bank.print();
cout << "Now that we have collected all the information from you regarding your income and expenses" << endl;
cout << "we will check whether your accounting is correct or not" << endl;
Bank.calculate();
Bank.cheakSaving();
}


	

int main() 
{
	BankAccount Bank;

	cout << "Enter your details" << endl;
	 Persondetails(Bank);

	cout << "View your bank account details" << endl;
	Bank_details(Bank);


	return 0;
}

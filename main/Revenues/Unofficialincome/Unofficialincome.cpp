#include "Unofficialincome.h"
#include <iostream>
using namespace std;


Unofficialincome::unofficialincome Unofficialincome::getType() const
{
	return Type;
}

void Unofficialincome::setType(unofficialincome type) 
{
	Type = type;
}

void Unofficialincome::print() const
{
    cout << "Unofficial income type: ";
    switch (Type) {
    case Inheritance:
        cout << "Inheritance";
        break;
    case Lotto:
        cout << "Lotto";
        break;
    case Scholarship:
        cout << "Scholarship";
        break;
    default:
        cout << "Unknown";
    }
    cout << ", Sum: " << Sum << endl;
}

int Unofficialincome::calculateIncome() {
    int typeChoice;
    cout << "Enter the income type (1 for Inheritance, 2 for Lotto, 3 for Scholarship): ";
    cin >> typeChoice;

   
    switch (typeChoice) {
    case 1:
        Type = Inheritance;
        break;
    case 2:
        Type = Lotto;
        break;
    case 3:
        Type = Scholarship;
        break;
    default:
        cout << "Invalid income type entered." << endl;
        return 1; 
    }

    cout << "Enter the income amount: ";
    cin >> Sum;

    return Sum;
}


ostream& operator<<(ostream& os, const Unofficialincome& in)
{
    os << in.Type;
    int size = 3;
    int type = 0;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter 1 for Fixedexpenes,Enter 2 for Onetimaexpenseand 3 for Combineexpense" << endl;
        cin >> type;

        switch (type)
        {
        case 1:
            os << in.Inheritance;
            break;
        case 2:
            os << in.Lotto;
            break;
        case 3:
            os << in.Scholarship;
            break;
        default:
            os << "Unknown";
        }
        os << ", Sum: " << in.Sum;
    }
    return os;

}


istream& operator>>(istream& is, Unofficialincome& num)
{


    int sum;
    cout << "Enter the sum of unofficial income: ";
    is >> sum;
    num.setSum(sum);

    int type;
    cout << "Enter the type of unofficial income (1 for Inheritance, 2 for Lotto, 3 for Scholarship): ";
    is >> type;
    switch (type) {
    case 1:
        num.setType(Unofficialincome::Inheritance);
        break;
    case 2:
        num.setType(Unofficialincome::Lotto);
        break;
    case 3:
        num.setType(Unofficialincome::Scholarship);
        break;
    default:
        
        cerr << "Invalid unofficial income type entered." << endl;
        break;
    }

    return is;
}


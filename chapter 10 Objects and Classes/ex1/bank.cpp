#include <iostream>
#include "bank.h"

Bank::Bank(const std::string acc_name, const std::string acc_number, double acc_balans)
{
	name = acc_name;
	number = acc_number;
	balans = acc_balans;
}

void Bank::show() const 
{
	using std::cout;
	cout << "Client name: " << name << ",   Accoutn number: " << number << ",   balans: $" << balans << std::endl;
}

void Bank::donate(double value) 
{
	if (value > 0)
	{
		balans += value;
	}
	else
	{
		std::cout << "Invalid value!\n";
	}
}

void Bank::get(double value)
{
	if (value < 0)
		std::cout << "Invalid value!\n";
	else if (value > balans)
		std::cout << "You can't get more then you have!\n";
	else
		balans -= value;
}
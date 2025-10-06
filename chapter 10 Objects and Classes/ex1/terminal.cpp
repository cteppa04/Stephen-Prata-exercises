#include <iostream>
#include "bank.h"

int main()
{
	using std::cout;

	Bank b1 = Bank ("Rodrig Diaz", "12", 100);
	b1.show();
	cout << "Add 40$ to account:\n";
	b1.donate(40);
	b1.show();
	Bank b2 = { "Bod er France", "14", 34 };
	b2.show();
	cout << "Get 35$ from account:\n";
	b2.get(35);
	cout << "Get 12$ from account:\n";
	b2.get(12);
	b2.show();

	cout << "Enter name for your accoutn: ";
	std::string name;
	getline(std::cin, name);
	cout << "Enter your account number: ";
	std::string number;
	getline(std::cin, number);

	Bank b3 { name, number };
	b3.show();

	return 0;
}
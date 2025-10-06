#include "header.h"

//
Wine::Wine(const char* l, int y, const int yr[], const int bot[]) : std::string(l), years(y), PairArray(ArrayInt(y), ArrayInt(y))
{
	for (int i = 0; i < years; i++)
	{
		(int&)PairArray::first()[i] = yr[i];
		(int&)PairArray::second()[i] = bot[i];
	}
}

void Wine::GetBottles()
{
	std::cout << "Enter " << (const std::string&)*this << " data for " << years << " year(s): \n";
	for (int i = 0; i < years; i++)
	{
		std::cout << "Enter year: ";
		std::cin >> PairArray::first()[i];
		std::cout << "Enter bottles for that year: ";
		std::cin >> PairArray::second()[i];
	}
}

void Wine::Show() const
{
	std::cout << "Wine: " << (const std::string&)*this << std::endl;
	std::cout << "		Year	Bottles\n";
	for (int i = 0; i < years; i++)
	{
		std::cout << "		";
		std::cout << PairArray::first()[i];
		std::cout << "	";
		std::cout << PairArray::second()[i];
		std::cout << std::endl;
	}
}

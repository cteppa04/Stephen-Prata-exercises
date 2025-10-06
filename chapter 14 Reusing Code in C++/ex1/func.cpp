#include "header.h"

//
Wine::Wine(const char* l, int y, const int yr[], const int bot[]) : label(l), years(y), pair_arr(ArrayInt(y), ArrayInt(y))
{
	for (int i = 0; i < years; i++)
	{
		(int&) pair_arr.first()[i] = yr[i];
		(int&) pair_arr.second()[i] = bot[i];
	}
}

void Wine::GetBottles()
{
	std::cout << "Enter " << label << " data for " << years << " year(s): \n";
	for (int i = 0; i < years; i++)
	{
		std::cout << "Enter year: ";
		std::cin >> pair_arr.first()[i];
		std::cout << "Enter bottles for that year: ";
		std::cin >> pair_arr.second()[i];
	}
}

void Wine::Show() const
{
	std::cout << "Wine: " << label << std::endl;
	std::cout << "		Year	Bottles\n";
	for (int i = 0; i < years; i++)
	{
		std::cout << "		";
		std::cout << pair_arr.first()[i];
		std::cout << "	";
		std::cout << pair_arr.second()[i];
		std::cout << std::endl;
	}
}

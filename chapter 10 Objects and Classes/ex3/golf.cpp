#include <iostream>
#include "golf.h"
#include <cstring>

Golf::Golf(const char* name, int hc)
{
	strcpy_s(fullname, Len, name);
	handicap = hc;
}

int Golf::setgolf()
{
	std::cout << "Enter name: ";
	char name[Len];
	std::cin.get(name, Len);
	if (name[0] == '\0')
	{
		std::cin.clear();
		return 0;
	}
	while (std::cin.get() != '\n')
		continue;
	int hc;
	std::cout << "Enter handicap: ";
	std::cin >> hc;
	std::cin.get();
	Golf temp = { name , hc };
	*this = temp;
	return 1;
}

void Golf::handicapf(int hc)
{
	handicap = hc;
}

void Golf::showgolf() const
{
	using std::cout;
	cout << "Name: " << fullname << ", handicap: " << handicap << std::endl;
}
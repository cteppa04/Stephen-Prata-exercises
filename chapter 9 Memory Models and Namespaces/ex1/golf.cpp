#include <iostream>
#include "golf.h"
#include <cstring>

void setgolf(golf& g, const char* name, int hc)
{
	strcpy_s(g.fullname, Len, name);
	g.handicap = hc;
}

int setgolf(golf& g)
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
	setgolf(g, name, hc);
	return 1;
}

void handicap(golf& g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf& g)
{
	using std::cout;
	cout << "Name: " << g.fullname << ", handicap: " << g.handicap << std::endl;
}
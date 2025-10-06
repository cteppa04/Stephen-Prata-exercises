#include "port.h"
#include <cstring>

Port::Port(const char* br, const char* st, int b)
{
	brand = new char[strlen(br) + 1];
	strcpy_s(brand, strlen(br) + 1, br);
	strcpy_s(style, strlen(st) + 1, st);
	if (b < 0)
	{
		cout << "Number of bottles can't be negative, set bottels to 0.\n";
		bottles = 0;
	}
	else
		bottles = b;
}

Port::Port(const Port& p)
{
	brand = new char[strlen(p.brand) + 1];
	strcpy_s(brand, strlen(p.brand) + 1, p.brand);
	strcpy_s(style, strlen(p.style) + 1, p.style);
	bottles = p.bottles;
}

Port& Port::operator=(const Port& p)
{
	if (this == &p)
		return *this;
	delete[] brand;
	brand = new char[strlen(p.brand) + 1];
	strcpy_s(brand, strlen(p.brand) + 1, p.brand);
	strcpy_s(style, strlen(p.style) + 1, p.style);
	bottles = p.bottles;
	return *this;
}

Port& Port::operator+=(int b)
{
	bottles += b;
	return *this;
}

Port& Port::operator-=(int b)
{
	if (b > bottles)
	{
		cout << "You cannot subtract more bottles than you have.\n";
		cout << "Subtract " << bottles << " bottles.\n";
		bottles = 0;
	}
	else
	{
		bottles -= b;
	}
	return *this;
}

void Port::Show() const
{
	cout << "Brand: " << brand << endl;
	cout << "Kind: " << style << endl;
	cout << "Bottles: " << bottles << endl;
}

ostream& operator<<(ostream& os, const Port& p)
{
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}
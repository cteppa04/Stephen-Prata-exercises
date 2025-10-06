#include "classic.h"
#include <iostream>
#include <cstring>

Classic::Classic(const char* s0, const char* s1, const char* s2, int n, double x) : Cd(s1, s2, n, x)
{
	primary_work = new char[strlen(s0) + 1];
	strcpy_s(primary_work, strlen(s0) + 1, s0);
}

Classic::Classic(const Classic& d) : Cd(d)
{
	primary_work = new char[strlen(d.primary_work) + 1];
	strcpy_s(primary_work, strlen(d.primary_work) + 1, d.primary_work);
}

Classic::Classic(const char* s, const Cd& d) : Cd(d)
{
	primary_work = new char[strlen(s) + 1];
	strcpy_s(primary_work, strlen(s) + 1, s);
}

Classic::Classic()
{
	primary_work = new char[5];
	strcpy_s(primary_work, 5, "none");
}

Classic::~Classic()
{
	delete[] primary_work;
}

void Classic::Report() const
{
	std::cout << "Primary work: " << primary_work << std::endl;
	Cd::Report();
}

Classic& Classic::operator=(const Classic& d)
{
	if (this == &d)
		return *this;
	Cd::operator=(d);
	delete[] primary_work;
	primary_work = new char[strlen(d.primary_work) + 1];
	strcpy_s(primary_work, strlen(d.primary_work) + 1, d.primary_work);
	return *this;
}
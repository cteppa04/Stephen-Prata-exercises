#include "classic.h"
#include <iostream>
#include <cstring>

Classic::Classic(const char* s0, const char* s1, const char* s2, int n, double x) : Cd(s1, s2, n, x)
{
	strcpy_s(primary_work, LEN - 1, s0);
	primary_work[LEN - 1] = '\0';
}

Classic::Classic(const Classic& d) : Cd(d)
{
	strcpy_s(primary_work, Classic::LEN - 1, d.primary_work);
	primary_work[LEN - 1] = '\0';
}

Classic::Classic()
{
	strcpy_s(primary_work, 5, "none");
}

Classic::~Classic()
{ }

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
	strcpy_s(primary_work, LEN - 1, d.primary_work);
	primary_work[LEN - 1] = '\0';
	return *this;
}
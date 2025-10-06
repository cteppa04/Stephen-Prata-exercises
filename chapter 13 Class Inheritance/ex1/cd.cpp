#include "cd.h"
#include "cstring"
#include <iostream>

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	strcpy_s(performers, 50, s1);
	performers[49] = '\0';
	strcpy_s(label, 20, s2);
	label[19] = '\0';
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd& d)
{
	strcpy_s(performers, 50, d.performers);
	performers[49] = '\0';
	strcpy_s(label, 20, d.label);
	label[19] = '\0';
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	strcpy_s(performers, 5, "none");
	strcpy_s(label, 5, "none");
	selections = 0;
	playtime = 0;
}

void Cd::Report() const
{
	std::cout << "Performers: " << performers << "\nLabel: " << label << "\nSelections: " << selections << "\nPlaytime: " << playtime << std::endl;
	std::cout << std::endl;
}

Cd& Cd::operator=(const Cd& d)
{
	if (this == &d)
		return *this;
	strcpy_s(performers, 50, d.performers);
	performers[49] = '\0';
	strcpy_s(label, 20, d.label);
	label[19] = '\0';
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}
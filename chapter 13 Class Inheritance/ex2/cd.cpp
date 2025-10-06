#include "cd.h"
#include "cstring"
#include <iostream>

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	performers = new char[strlen(s1) + 1];
	strcpy_s(performers, strlen(s1) + 1, s1);
	performers[strlen(s1)] = '\0';
	label = new char[strlen(s2) + 1];
	strcpy_s(label, strlen(s2) + 1, s2);
	label[strlen(s2)] = '\0';
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd& d)
{
	performers = new char[strlen(d.performers) + 1];
	strcpy_s(performers, strlen(d.performers) + 1, d.performers);
	label = new char[strlen(d.label) + 1];
	strcpy_s(label, strlen(d.label)	+ 1, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	performers = new char[5];
	strcpy_s(performers, 5, "none");
	label = new char[5];
	strcpy_s(label, 5, "none");
	selections = 0;
	playtime = 0;
}

Cd::~Cd()
{
	delete[] performers;
	delete[] label;
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
	delete[] performers;
	performers = new char[strlen(d.performers) + 1];
	strcpy_s(performers, strlen(d.performers) + 1, d.performers);
	delete[] label;
	label = new char[strlen(d.label) + 1];
	strcpy_s(label, strlen(d.label) + 1, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}
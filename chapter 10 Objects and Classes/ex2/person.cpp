#include <iostream>
#include <cstring>
#include "person.h"

Person::Person(const std::string& ln, const char* fn)
{
	lname = ln;
	strcpy_s(fname, LIMIT, fn);
	fname[LIMIT] = '\0';
}

void Person::Show() const
{
	std::cout << "Normal: " << fname << " " << lname << std::endl;
}

void Person::FormalShow() const
{
	std::cout << "Formal: " << lname << " " << fname << std::endl;
}
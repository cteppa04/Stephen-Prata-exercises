#include "classs.h"
#include <iostream>
#include <cstring>

Cow::Cow()
{
	name[0] = '\0';
	hobby = new char[1];
	hobby[0] = '\0';
	weight = 0;
}

Cow::Cow(const char* nm, const char* ho, double wt)
{
	strcpy_s(name, 20, nm);
	name[19] = '\0';
	hobby = new char[strlen(ho) + 1];
	strcpy_s(hobby, strlen(ho) + 1, ho);
	weight = wt;
}

Cow::Cow(const Cow& c)
{
	strcpy_s(name, 20, c.name);
	delete[] hobby;
	hobby = new char[strlen(c.hobby) + 1];
	strcpy_s(hobby, strlen(c.hobby) + 1, c.hobby);
	weight = c.weight;
}

Cow::~Cow()
{
	delete[] hobby;
}

Cow& Cow::operator=(const Cow& c)
{
	if (this == &c)
		return *this;
	strcpy_s(name, 20, c.name);
	delete[] hobby;
	hobby = new char[strlen(c.hobby) + 1];
	strcpy_s(hobby, strlen(c.hobby) + 1, c.hobby);
	weight = c.weight;
	return *this;
}

void Cow::ShowCow() const
{
	std::cout << "Name: " << name << ", Hobby: " << hobby << ", Weight: " << weight << std::endl;
}
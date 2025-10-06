#include <iostream>
#include "prolog.h"
#include <cstring>

Plorga::Plorga(const char* pname, int pci)
{
	strcpy_s(name, SIZE, pname);
	name[SIZE - 1] = '\0';
	ci = pci;
}

void Plorga::change_ci(int pci)
{
	ci = pci;
}

void Plorga::show()
{
	using std::cout;
	cout << "Info:\n";
	cout << "Name: " << name << ", ci = " << ci << std::endl << std::endl;
}
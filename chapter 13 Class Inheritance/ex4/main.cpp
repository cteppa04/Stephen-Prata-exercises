#include "vintageport.h"
#include <iostream>

int main()
{
	VintagePort p1("Ringo", 12, "hgjf", 6);
	p1 += 5;
	cout << p1;
	return 0;
}
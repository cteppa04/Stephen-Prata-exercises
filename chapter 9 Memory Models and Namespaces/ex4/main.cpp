#include <iostream>
#include "header.h"

int main()
{
	using SALES::setSales;
	SALES::Sales s1, s2;

	double arr[7] = { 1,8,5,64,7,0,4 };

	setSales(s1);
	SALES::showSales(s1);

	setSales(s2, arr, 5);
	SALES::showSales(s2);

	return 0;
}
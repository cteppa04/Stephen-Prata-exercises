#include <iostream>
#include "header.h"

int main()
{
	using SALES::Sales;
	Sales s1, s2;

	double arr[7] = { 1,8,5,64,7,0,4 };

	s1.setSales();
	s1.showSales();

	s2 = Sales(arr, 6);
	s2.showSales();

	return 0;
}
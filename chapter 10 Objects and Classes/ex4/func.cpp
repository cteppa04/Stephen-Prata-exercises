#include <iostream>
#include "header.h"

namespace SALES
{
	Sales::Sales()
	{

	}

	Sales::Sales(const double ar[], int n)
	{
		double* temp_arr = new double[n];
		double temp;
		double sum = 0;

		for (int i = 0; i < n; i++)
		{
			temp_arr[i] = ar[i];
		}
		for (int i = 0; i < n; i++)
			for (int j = n - 1; j >= i; j--)
				if (temp_arr[i] > temp_arr[j])
				{
					temp = temp_arr[i];
					temp_arr[i] = temp_arr[j];
					temp_arr[j] = temp;
				}

		min = temp_arr[0];
		for (int i = 0; i < QUARTERS; i++)
		{
			if (n > i)
			{
				sales[i] = temp_arr[i];
				max = sales[i];
				sum += sales[i];
			}
			else
			{
				sales[i] = 0;
				min = 0;
			}
		}
		average = sum / QUARTERS;

		delete[] temp_arr;
	}

	void Sales::setSales()
	{
		using std::cout;
		using std::cin;
		using std::endl;
		double sum = 0;
		double arr[QUARTERS] = {};

		for (int i = 0; i < QUARTERS; i++)
		{
			cout << "Enter sale #" << i + 1 << ": ";
			while (!(cin >> arr[i]))
			{
				cin.clear();
				while (cin.get() != '\n')
					continue;
				cout << "Wrong input, try again: ";
			}
		}
		*this = Sales (arr);
	}

	void Sales::showSales() const
	{
		using std::cout;
		using std::endl;
		cout << "Sales:\n";
		for (int i = 0; i < QUARTERS; i++)
		{
			cout << "Sale of #" << i + 1 << " quarters: " << sales[i] << endl;
		}
		cout << "Average: " << average << ",   Max: " << max << ",   Min: " << min << endl;
	}
}
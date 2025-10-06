#include <iostream>
#include "header.h"

namespace SALES
{
	void setSales(Sales& s, const double ar[], int n)
	{
		double* temp_arr = new double[n];
		double temp;
		double sum = 0;

		for (int i = 0; i < n; i++)
		{
			temp_arr[i] = ar[i];
		}
		for (int i = 0; i < n; i ++)
			for (int j = n - 1; j >= i; j--)
				if (temp_arr[i] > temp_arr[j])
				{
					temp = temp_arr[i];
					temp_arr[i] = temp_arr[j];
					temp_arr[j] = temp;
				}

		s.min = temp_arr[0];
		for (int i = 0; i < QUARTERS; i++)
		{
			if (n > i)
			{
				s.sales[i] = temp_arr[i];
				s.max = s.sales[i];
				sum += s.sales[i];
			}
			else
			{
				s.sales[i] = 0;
				s.min = 0;
			}
		}
		s.average = sum / 4;
		
		delete[] temp_arr;
	}

	void setSales(Sales& s)
	{
		using std::cout;
		using std::cin;
		using std::endl;
		double sum = 0;

		for (int i = 0; i < QUARTERS; i++)
		{
			cout << "Enter sale #" << i + 1 << ": ";
			while (!(cin >> s.sales[i]))
			{
				cin.clear();
				while (cin.get() != '\n')
					continue;
				cout << "Wrong input, try again: ";
			}
			sum += s.sales[i];
		}
		s.average = sum / QUARTERS;
		
		double temp;
		s.max = s.min = s.sales[0];
		for (int i = 0; i < QUARTERS; i++)
		{
			if (s.sales[i] > s.max) s.max = s.sales[i];
			if (s.sales[i] < s.min) s.min = s.sales[i];
		}
	}

	void showSales(const Sales& s)
	{
		using std::cout;
		using std::endl;
		cout << "Sales:\n";
		for (int i = 0; i < QUARTERS; i++)
		{
			cout << "Sale of #" << i + 1 << " quarters: " << s.sales[i] << endl;
		}
		cout << "Average: " << s.average << ",   Max: " << s.max << ",   Min: " << s.min << endl;
	}
}
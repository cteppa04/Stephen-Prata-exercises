#include <iostream>
using namespace std;

const int Size = 10;

int Fill_array(double arr[], int n);
void Show_array(const double arr[], int n);
void Reverse_array(double arr[], int n);

int main()
{
	double arr[Size];
	int limit;
	limit = Fill_array(arr, Size);
	Reverse_array(arr, limit);
	Show_array(arr, limit);
	return 0;
}

int Fill_array(double arr[], int n)
{
	double temp;
	int i = 0;
	cout << "Enter " << Size << " elements of array(q to quit): \n";
	for (i = 0; i < n; i++)
	{
		cout << "Enter " << i + 1 << " element of array: ";
		if (cin >> temp)
		{
			arr[i] = temp;
		}
		else 
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			break;
		}
	}
	return i;
}

void Show_array(const double arr[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << "Element " << i + 1 << "#: " << arr[i] << endl;
	}
}

void Reverse_array(double arr[], int n)
{
	double temp = 0;
	int lim = n - 2;
	for (int i = 1; i < lim; i++, lim--)
	{
		temp = arr[i];
		arr[i] = arr[lim];
		arr[lim] = temp;
	}
}
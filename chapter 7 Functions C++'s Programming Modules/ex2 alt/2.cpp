#include <iostream>
using namespace std;
const int Size = 10;

int input(double arr[], int limit);
void output(double arr[], int n);
void avg(double arr[], int n);

int main()
{
	double arr[Size];
	int limit = input(arr, Size);
	output(arr, limit);
	avg(arr, limit);
	return 0;
}

int input(double arr[], int limit)
{
	cout << "Enter 10 numbers(q to quit):\n";
	int i;
	double temp;
	for (i = 0; i < limit; ++i)
	{
		cout << "#" << i + 1 << ": ";
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "End of input.\n";
			break;
		}
		else if (temp < 0)
		{
			break;
		}
		else
		{
			arr[i] = temp;
		}
	}
	return i;
}

void output(double arr[], int n)
{
	if (n != 0)
	{
		cout << "Wyniki: ";
		for (int i = 0; i < n; ++i)
		{
			cout << "#" << i + 1 << ": " << arr[i] << "   ";
		}
	}
	else
	{
		cout << "Nie ma wynikow.\n";
	}
}

void avg(double arr[], int n)
{
	if (n != 0)
	{
		double sum = 0;
		int i;
		for (i = 0; i < n; ++i)
		{
			sum += arr[i];
		}
		cout << "AVG: " << sum / i << endl;
	}
}
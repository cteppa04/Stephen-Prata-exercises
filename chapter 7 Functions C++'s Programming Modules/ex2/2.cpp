#include <iostream>
using namespace std;

const int Size = 10;

void input(int golf_result[], int n);
void output(const int golf_result[], int n, double avg);
double avg(const int golf_result[], int n);

int main()
{
	int golf_result[Size];
	input(golf_result, Size);
	output(golf_result, Size, avg(golf_result, Size));
	return 0;
}

void input(int golf_result[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << "Enter result #" << i + 1 << "(q to quit): ";
		if (cin >> golf_result[i])
			continue;
		else
			while (cin.get() != '\n')
			{
				cin.clear();
			}
			break;
	}
}

void output(const int golf_result[], int n, double avg)
{
	int i;
	for (i = 0; i < n && golf_result[i]; ++i)
	{
		cout << "#" << i + 1 << ": " << golf_result[i] << ", ";
	}
	cout << "avg = " << avg << endl;
}

double avg(const int golf_result[], int n)
{
	int i;
	double sum = 0;
	for (i = 0; i < n && golf_result[i]; ++i)
	{
		sum = sum + golf_result[i];
	}
	if (i == 0)
		return 0;
	return sum / i;
}
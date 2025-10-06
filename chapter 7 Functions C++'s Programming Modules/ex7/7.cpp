#include <iostream>

const int Max = 5;

double* fill_array(double* pt1, double* pt2);
void show_array(const double arr[], const double* size);
void revalue(double r, double* arr, const double* size);

int main()
{
	using namespace std;

	double properties[Max];
	const double* size = fill_array(properties, properties + Max);
	show_array(properties, size);
	cout << size - properties << endl;
	if (size - properties > 0)
	{
		cout << "Enter revaluation factor: ";
		double factor;
		while (!(cin >> factor))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; Please enter a number: ";
		}
		revalue(factor, properties, size);
		show_array(properties,  size);
	}

	cout << "Done.\n";

	return 0;
}

double* fill_array(double* start, double* end)
{
	using namespace std;
	double temp;
	double* pt;
	int i;
	for (pt = start, i = 1; pt != end; pt++, i++)
	{
		cout << "Enter value #" << i << ": $";
		cin >> temp;

		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; input process terminated.\n";
			break;
		}
		else if (temp < 0)
			break;
		*pt = temp;
	}
	return pt;
}

void show_array(const double* start, const double* end)
{
	using namespace std;
	const double* pt;
	int i;
	for (i = 1, pt = start; pt != end; pt++, i++)
	{
		cout << "Property #" << i << ": $";
		cout << *pt << endl;
	}
}

void revalue(double r, double* start, const double* end)
{
	for (double* pt = start; pt != end; pt++)
		*pt *= r;
}
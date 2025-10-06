#include <iostream>
double convert(double);

int main()
{
	using namespace std;
	cout << "Enter the number of light years: ";
	double light_years;
	cin >> light_years;
	cout << light_years << " light years = " << convert(light_years) << " astronomical units." << endl;
	return 0;
}

double convert(double n)
{
	return n * 63240;
}
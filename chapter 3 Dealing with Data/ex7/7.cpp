#include <iostream>

int main()
{
	using namespace std;
	const double km_to_mile = 62.14 / 100;
	const double liter_to_gallon = 1 / 3.875;

	double miles, gall, km, liters;
	double miles_to_gall;

	km = 100;
	miles = km * km_to_mile;

	cout << "Enter liters to 100 km: ";
	cin >> liters;

	gall = liters * liter_to_gallon;

	miles_to_gall = miles / gall;

	cout << liters << " liters to km = " << miles_to_gall << " miles to gallon." << endl;

	return 0;
}
#include <iostream>

int main()
{
	using namespace std;
	double degrees, minutes, seconds;
	double degrees_double;
	const int sec_to_min = 60;
	const int min_to_deg = 60;

	cout << "Enter a latitude in degrees, minutes and seconds:\n";
	cout << "First, enter the degrees: ";
	cin >> degrees;
	cout << "Next, enter the minutes of arc: ";
	cin >> minutes;
	cout << "Finally, enter the seconds of arc: ";
	cin >> seconds;
	degrees_double = degrees + (minutes + seconds / sec_to_min) / min_to_deg;
	cout << degrees << " degrees, " << minutes << " minutes, " << seconds << " seconds = " << degrees_double << " degrees." << endl;

	return 0;
}
#include <iostream>

int main()
{
	using namespace std;
	const int sec_in_min = 60;
	const int min_in_hour = 60;
	const int hour_in_day = 24;
	int days, hours, minutes, seconds_int;

	cout << "Enter the number of seconds: ";
	long long seconds;
	cin >> seconds;

	days = seconds / sec_in_min / min_in_hour / hour_in_day;
	hours = seconds / sec_in_min / min_in_hour % hour_in_day;
	minutes = seconds / sec_in_min % min_in_hour;
	seconds_int = seconds % sec_in_min;

	cout << seconds << " seconds = " << days << " days, " << hours << " hours, " << minutes << " minutes, " 
		 << seconds_int << " seconds." << endl;

	return 0;
}
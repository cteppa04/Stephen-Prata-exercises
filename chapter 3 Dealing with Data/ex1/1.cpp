#include <iostream>

int main()
{
	using namespace std;
	
	const int inch_to_feet = 12;
	cout << "Enter your height in inches:__\b\b";
	int inch;
	cin >> inch;
	int feet = inch / inch_to_feet;
	inch = inch % inch_to_feet;
	cout << "Your height is " << feet << " feets and " << inch << " inches.";

	return 0;
}
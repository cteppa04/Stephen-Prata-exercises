#include <iostream>

int main()
{
	using namespace std;

	const int feet_to_inch = 12;
	const double lbs_to_kg = 2.2;
	const double inch_to_m = 0.0254;

	int feet, inch, lbs;
	double kg, m, BMI;

	cout << "Enter your height:\nFeets: ";
	cin >> feet;
	cout << "Inches: ";
	cin >> inch;
	cout << "Enter your weight in lbs: ";
	cin >> lbs;

	inch = inch + feet * feet_to_inch;
	kg = lbs / lbs_to_kg;
	m = inch * inch_to_m;

	BMI = kg / pow(m, 2);

	cout << "Your BMI = " << BMI << endl;

	return 0;
}
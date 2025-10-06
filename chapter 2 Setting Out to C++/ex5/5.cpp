#include <iostream>
double convert(int);

int main()
{
	using namespace std;
	cout << "Enter a celsius value: ";
	int cels;
	cin >> cels;
	int far = convert(cels);
	cout << cels << " degrees Celsius is " << far << " degrees Fahrenheit.";
	return 0;
}

double convert(int n) 
{
	return n * 1.8 + 32;
}
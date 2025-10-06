#include <iostream>

int main()
{
	using namespace std;

	int km, l;
	double l_to_100km;
	
	cout << "Enter km's: ";
	cin >> km;
	cout << "Enter liters: ";
	cin >> l;
	l_to_100km = 100 * double (l) / double (km);

	cout << l_to_100km << " liters to 100km." << endl;

	return 0;
}
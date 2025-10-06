#include <iostream>
#include <array>

int main()
{
	using namespace std;

	array<double, 4> run;

	cout << "Enter first result: ";
	cin >> run[0];
	cout << "Enter second result: ";
	cin >> run[1];
	cout << "Enter third result: ";
	cin >> run[2];
	
	run[3] = (run[0] + run[1] + run[2]) / 3;

	cout << "Results:\n";
	cout << "1) " << run[0] << endl;
	cout << "2) " << run[1] << endl;
	cout << "3) " << run[2] << endl;
	cout << "AVG: " << run[3] << endl;

	return 0;
}
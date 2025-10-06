#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter first number: ";
	int i;
	cin >> i;
	cout << "Enter second number: ";
	int j;
	cin >> j;
	int sum = 0;

	while (i <= j)
	{
		sum += i;
		++i;
	}

	cout << "Sum = " << sum << endl;

	return 0;
}
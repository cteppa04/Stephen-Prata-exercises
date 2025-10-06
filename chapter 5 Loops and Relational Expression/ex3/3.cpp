#include <iostream>

int main()
{
	using namespace std;

	int sum = 0;
	int i;
	
	cout << "Enter number(0 to quit): ";

	while (cin >> i)
	{
		sum += i;
		cout << "Sum = " << sum << endl;
		cout << "Enter number(0 to quit): ";
	}

	cout << "Final sum = " << sum << endl;

	return 0;
}
#include <iostream>	

long double factorial(int n);

int main()
{
	using namespace std;
	int n;
	cout << "Enter an integer: ";
	while (cin >> n && n >= 0)
	{
		cout << "Factorial of this number is " << factorial(n) << endl;
		cout << "Enter another integer(q to quit): ";
	}
	cout << "Done.\n";
	return 0;
}

long double factorial(int n)
{
	if (n == 0)
		return 1;
	else
	{
		return n * factorial(n - 1);
	}
}
#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter number of strings: ";
	int count;
	cin >> count;

	for (int licz = 0; licz < count; ++licz)
	{
		for (int i = count - licz; i > 1; --i)
		{
			cout << ".";
		}
		for (int j = 0; j <= licz; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}
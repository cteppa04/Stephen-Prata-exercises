#include <iostream>

int main()
{
	using namespace std;

	double value;
	double taxes;
	
	cout << "Enter value: ";

	while (cin >> value and value >= 0)
	{
		cout << "Value = " << value << ", taxes = ";
		if (value <= 5000)
		{
			taxes = value * 0;
		}
		else if (value <= 15000)
		{
			value = value - 5000;
			taxes = value * 0.1;
		}
		else if (value <= 35000)
		{
			value = value - 15000;
			taxes = 10000 * 0.1 + value * 0.15;
		}
		else
		{
			value = value - 35000;
			taxes = 10000 * 0.1 + 20000 * 0.15 + value * 0.2;
		}
		cout << taxes << endl;
		cout << "Enter next value: ";
	}
	
	cout << "Bye!\n";
		
	return 0;
}
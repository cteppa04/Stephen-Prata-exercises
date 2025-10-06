#include <iostream>

double add(double x, double y);
double sub(double x, double y);
double multi(double x, double y);
double div(double x, double y);
double calculate(double num1, double num2, double (*pt)(double x, double y));

int main()
{
	using namespace std;
	double (*pt[4])(double x, double y) = { add, sub, multi, div };
	cout << "Enter two numbers: ";
	double x, y;
	int choise;
	double* result = new double;
	while (cin >> x >> y)
	{
		cout << "Choise an operation:\n";
		cout << "1)addition		2)subtraction\n";
		cout << "3)multiplication	4)division\n";
		cout << "5)quit\n";
		cin >> choise;
		if (choise == 5)
			break;
		else if (choise == 4 && y == 0)
		{
			cout << "Can't division when second number is 0.\n";
			cout << "Enter another two numbers: ";
			continue;
		}
		*result = calculate(x, y, (*pt[choise - 1]));
		cout << "Result is " << *result << endl;
		cout << "Enter another two numbers: ";
	}
	cout << "Done\n";
	delete result;
	return 0;
}

double add(double x, double y)
{
	return x + y;
}

double sub(double x, double y)
{
	return x - y;
}

double multi(double x, double y)
{
	return x * y;
}

double div(double x, double y)
{
	return x / y;
}

double calculate(double x, double y, double (*pt)(double num1, double num2))
{
	return (*pt)(x, y);
}
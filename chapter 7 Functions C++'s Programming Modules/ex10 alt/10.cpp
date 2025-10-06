#include <iostream>

const int Size = 4;
const char* op_name[Size] = { "addition", "subtraction", "multiplication", "division" };

double add(double x, double y);
double sub(double x, double y);
double multi(double x, double y);
double div(double x, double y);
void calculate(double num1, double num2, double (*pt[])(double x, double y), int size, const char * op_name[]);

int main()
{
	using namespace std;
	double (*pt[4])(double x, double y) = { add, sub, multi, div };
	cout << "Enter two numbers: ";
	double x, y;
	while (cin >> x >> y)
	{
		calculate(x, y, pt, Size, op_name);
		cout << "Enter another two numbers(q to quit): ";
	}
	cout << "Done\n";
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

void calculate(double num1, double num2, double (*pt[])(double x, double y), int size, const char * op_name[])
{
	using namespace std;
	for (int i = 0; i < size; i++)
	{
		cout << "Operation " << op_name[i] << " result: " << (*pt[i])(num1, num2) << endl;
	}
}
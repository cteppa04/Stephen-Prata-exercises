#include <iostream>
#include <array>

int main()
{
	using namespace std;

	const int size = 100;

	array<long double, size> factorials;
	factorials[1] = factorials[0] = 1L;

	for (int i = 2; i < size; i++)
		factorials[i] = factorials[i-1] * i;

	for (int i = 0; i < size; i++)
		cout << i << "! = " << factorials[i] << endl;

	return 0;
}
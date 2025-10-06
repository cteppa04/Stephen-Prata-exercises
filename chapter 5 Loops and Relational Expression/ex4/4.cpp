#include <iostream>

int main()
{
	using namespace std;

	int dafna = 100;
	double kleo = 100;
	int count = 0;

	do
	{
		cout << count << " year, dafna have " << dafna << ", kleo have " << kleo << endl;
		dafna += 10;
		kleo *= 1.05;
		++count;
	} while (dafna > kleo);

	cout << count << " years need, dafna have " << dafna << ", kleo have " << kleo << endl;

	return 0;
}
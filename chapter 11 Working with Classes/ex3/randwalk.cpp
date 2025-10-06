#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vect.h"

int main()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0, 0);
	double target;
	double dstep;
	unsigned long steps = 0;

	double avg;
	unsigned long tries, sum, min, max;

	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		sum = 0;
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		cout << "Enter tries: ";
		if (!(cin >> tries))
			break;
		for (int i = 0; i < tries; i++)
		{
			while (result.magval() < target)
			{
				direction = rand() % 360;
				step.reset(dstep, direction, Vector::POL);
				result = result + step;
				steps++;
			}
			sum += steps;
			if (i == 0)	min = max = steps;
			if (steps > max) max = steps;
			if (steps < min) min = steps;
			steps = 0;
			result.reset(0.0, 0.0);
		}
		avg = double(sum) / tries;
		cout << "For " << tries << " tries:\n";
		cout << "All = " << sum << " steps, Avg = " << avg << " steps" << endl;
		cout << "Min = " << min << " steps, Max = " << max << " steps" << endl << endl;
		cout << "Enter target distance (q to quit): ";
		
	}
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
	return 0;
}
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vect.h"
#include <fstream>

int main()
{
	using namespace std;
	using VECTOR::Vector;
	ofstream file1;
	file1.open("out.txt");	
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0, 0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		if (file1.is_open()) 
		{
			cout << "Enter step length: ";
			if (!(cin >> dstep))
				break;
			file1 << "Target Distance: " << target << ", Step Size: " << dstep << "\n";
			while (result.magval() < target)
			{
				file1 << steps << ": " << result << endl;
				direction = rand() % 360;
				step.reset(dstep, direction, Vector::POL);
				result = result + step;
				steps++;

			}
			file1 << steps << ": " << result << endl;
			file1 << "After " << steps << " steps, the subject has the following location:\n";
			file1 << result << endl;
			result.polar_mode();
			file1 << " or\n" << result << endl;
			file1 << "Average outward distance per step = "
				<< result.magval() / steps << endl;
			steps = 0;
			result.reset(0.0, 0.0);
			cout << "Enter target distance (q to quit): ";
		}
		else
		{
			cout << "File not open.\n";
		}
	}
	file1.close();
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
	return 0;
}
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"
const int MIN_PER_HR = 60;

bool newcustomer(double x);

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;

	//rand
	int qs;
	int hours = 100;
	double perhour;
	
	long cyclelimit = MIN_PER_HR * hours;
	double min_per_cust;
	Item temp;
	
	//0
	long line_wait;
	long turnways;
	long customers;
	long served;
	long sum_line;
	int wait_time;
	
	int i = 60;

	std::srand(std::time(0));
	cout << "Case Study: Bank of Heather Automatic Teller\n";
	//cout << "Enter maximum size of queue: ";
	//cin >> qs;
	//cout << "Enter the number of simulation hours: ";
	//cin >> hours;
	//cout << "Enter the average number of customers per hour: ";
	//cin >> perhour;
	
	do
	{
		perhour = i--;
		qs = perhour * hours;
		Queue line(qs);
		line_wait = 0;
		turnways = 0;
		customers = 0;
		served = 0;
		sum_line = 0;
		wait_time = 0;
		min_per_cust = MIN_PER_HR / perhour;
		for (int cycle = 0; cycle < cyclelimit; cycle++)
		{
			if (newcustomer(min_per_cust))
			{
				if (line.isfull())
					turnways++;
				else
				{
					customers++;
					temp.set(cycle);
					line.enqueue(temp);
				}
			}
			if (wait_time <= 0 && !line.isempty())
			{
				line.dequeue(temp);
				wait_time = temp.ptime();
				line_wait += cycle - temp.when();
				served++;
			}
			if (wait_time > 0)
				wait_time--;
			sum_line += line.queuecount();
		}
		line.~Queue();
	} while ((double)line_wait / served > 1);
	i++;

	if (customers > 0)
	{
		cout << "Queue size: " << qs << ", Hours: " << hours << ", Customers per hour: " << perhour << endl;
		cout << "customers accepted: " << customers << endl;
		cout << " customers served: " << served << endl;
		cout << "	turnways: " << turnways << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double)sum_line / cyclelimit << endl;
		cout << " average wait time: "
			<< (double)line_wait / served << " minutes\n";
	}
	else
	{
		cout << "No customers.\n";
	}
	cout << "Done!\n";

	return 0;
}

bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}
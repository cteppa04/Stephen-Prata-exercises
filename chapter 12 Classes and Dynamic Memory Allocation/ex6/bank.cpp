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

	long line_wait1;
	long turnways1;
	long customers1;
	long served1;
	long sum_line1;
	int wait_time1;

	long line_wait2;
	long turnways2;
	long customers2;
	long served2;
	long sum_line2;
	int wait_time2;

	double avg_wait;


	std::srand(std::time(0));
	cout << "Case Study: Bank of Heather Automatic Teller\n";
	//cout << "Enter maximum size of queue: ";
	//cin >> qs;
	//cout << "Enter the number of simulation hours: ";
	//cin >> hours;
	//cout << "Enter the average number of customers per hour: ";
	//cin >> perhour;

	int i = 120;

	do
	{
		perhour = i--;	
		qs = perhour * hours / 2;
		Queue line1(qs);
		Queue line2(qs);
		line_wait2 = line_wait1 = 0;
		turnways2 = turnways1 = 0;
		customers2 = customers1 = 0;
		served2 = served1 = 0;
		sum_line2 = sum_line1 = 0;
		wait_time2 = wait_time1 = 0;
		min_per_cust = MIN_PER_HR / perhour;

		for (int cycle = 0; cycle < cyclelimit; cycle++)
		{
			if (newcustomer(min_per_cust))
			{
				if (line1.queuecount() <= line2.queuecount())
				{
					if (line1.isfull())
						turnways1++;
					else
					{
						customers1++;
						temp.set(cycle);
						line1.enqueue(temp);
					}
				}
				else
				{
					if (line2.isfull())
						turnways2++;
					else
					{
						customers2++;
						temp.set(cycle);
						line2.enqueue(temp);
					}
				}
			}
			if (wait_time1 <= 0 && !line1.isempty())
			{
				line1.dequeue(temp);
				wait_time1 = temp.ptime();
				line_wait1 += cycle - temp.when();
				served1++;
			}
			if (wait_time2 <= 0 && !line2.isempty())
			{
				line2.dequeue(temp);
				wait_time2 = temp.ptime();
				line_wait2 += cycle - temp.when();
				served2++;
			}
			if (wait_time1 > 0)
				wait_time1--;
			if (wait_time2 > 0)
				wait_time2--;

			sum_line1 += line1.queuecount();
			sum_line2 += line2.queuecount();

		}

		line1.~Queue();
		line2.~Queue();

		avg_wait = double(line_wait1 + line_wait2) / (served1 + served2);

	} while (avg_wait > 1.0);
	i++;

	if (customers1 + customers2 > 0)
	{
		cout << "Queue size: " << perhour * hours / 2 << ", Hours: " << hours << ", Customers per hour: " << i << endl;
		cout << "customers accepted: " << customers1 + customers2 << endl;
		cout << " customers served: " << served1 + served2 << endl;
		cout << "	turnways: " << turnways1 + turnways2 << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double) (sum_line1 * sum_line1 + sum_line2 * sum_line2) / (cyclelimit * (sum_line1 + sum_line2))  << endl;
		cout << " average wait time: "
			<< avg_wait << " minutes\n";
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
#include <iostream>
using std::cout;
#include "stonewt.h"

const int Arr_size = 6;

void display(const Stonewt& st, int n);

int main()
{
	Stonewt incognito = 275;
	Stonewt wolfe(285.7);
	Stonewt taft(21, 8);
	cout << "The celebrity weighed ";
	incognito.show_stn();
	cout << "The detective weighed ";
	wolfe.show_stn();
	cout << "The President weighed ";
	taft.show_lbs();
	incognito = 276.8;
	taft = 325;
	cout << "After dinner, the selebrity weighed ";
	incognito.show_stn();
	cout << "After dinner, the detective weighed ";
	taft.show_lbs();
	cout << "The wrestler weighed even move.\n";
	display(422, 2);
	cout << "No stone left unearned\n\n";

	Stonewt stones[Arr_size] = { 141.1,444.7,72.0 };
	Stonewt eleven_s(11, 0);
	int count, min, max;
	count = min = max = 0;
	double value;
	for (int i = 0; i < Arr_size; i++)
	{
		if (stones[i] == 0)
		{
			cout << "#" << i + 1 << " is not define.\n";
			cout << "Entet value in pounds: ";
			std::cin >> value;
			stones[i] = value;
		}
		else
		{
			cout << "#" << i + 1 << ": ";
			stones[i].show_lbs();
		}
		if (stones[i] > stones[max]) max = i;
		if (stones[i] < stones[min]) min = i;
		if (stones[i] >= eleven_s) count++;
	}
	cout << "Min = ";
	stones[min].show_stn();
	cout << "Max = ";
	stones[max].show_stn();
	cout << count << " objects weight more or equal then 11 stones.\n";

	return 0;
}

void display(const Stonewt& st, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "WOW! ";
		st.show_stn();
	}
}
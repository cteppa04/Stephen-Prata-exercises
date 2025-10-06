#include <iostream>
using std::cout;
#include "stonewt.h"

void display(const Stonewt& st, int n);

int main()
{
	Stonewt incognito = 275;
	Stonewt wolfe(285.7);
	Stonewt taft(21, 8);
	taft = taft * 8;
	taft.setIPds();
	cout << taft;
	Stonewt igi = wolfe - incognito + taft;
	igi.setPds();
	cout << igi;
	display(442, 4);
	return 0;
}

void display(const Stonewt& st, int n)
{
	for (int i = 0; i < n; i++)
		cout << "Wow! " << st;
}
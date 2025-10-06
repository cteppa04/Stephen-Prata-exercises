#include "prolog.h"

int main()
{
	Plorga p1;
	p1.change_ci(34);
	p1.show();

	Plorga p2("Rekoddddddddddddda", 45);
	p2.change_ci(66);
	p2.show();

	Plorga p3 = { "EGD", 99 };
	p3.show();

	return 0;
}
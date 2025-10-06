#include "classs.h"
#include <iostream>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	Cow c1;
	Cow c2("Gilberto Sab", "Book", 220);
	c2.ShowCow();
	c1.ShowCow();
	c1 = c2;
	c1.ShowCow();
	Cow c3 = Cow(c1);
	c3.ShowCow();

	return 0;
}
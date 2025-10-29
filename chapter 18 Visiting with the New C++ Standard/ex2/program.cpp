#include "cpmv.h"
#include <iostream>

int main()
{
	Cpmv obj1;
	obj1.Display();

	Cpmv obj2("first", "second");
	obj2.Display();

	Cpmv obj3(obj2);
	obj3.Display();

	Cpmv obj4(std::move(obj3));
	obj4.Display();

	Cpmv obj5;
	obj5 = obj4;
	obj5.Display();

	Cpmv obj6;
	obj6 = (obj4 + obj5);
	obj6.Display();

	Cpmv obj7(std::move(Cpmv("one", "two")));
	obj7.Display();

	return 0;
}
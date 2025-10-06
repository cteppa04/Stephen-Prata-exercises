#include "move.h"

int main()
{
	using namespace std;	

	Move o1(1, 4);
	o1.showmove();
	Move o2(63, 23);
	o2.showmove();
	Move o3 = o1.add(o2);
	o3.showmove();
	o2.reset(23, 55);
	o2.showmove();

	return 0;
}
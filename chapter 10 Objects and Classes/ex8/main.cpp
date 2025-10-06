#include <iostream>
#include <cctype>
#include "list.h"

void change(Item&);
void sqr(Item&);

int main()
{
	using namespace std;
	List l1;
	char ch;
	unsigned long po;
	cout << "Pleade enter A to add a purchase order,\n"
		<< "P to empty chack a PO,\n"
		<< "S to squar all elements,\n"
		<< "M to modify or Q to quit.\n";
	while (cin >> ch && toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		switch (ch)
		{
		case 'A':
		case 'a': cout << "Enter a PO number to add: ";
			cin >> po;
			if (l1.isfull())
				cout << "stack already full\n";
			else
				l1.push(po);
			break;

		case 'P':
		case 'p':
			if (l1.isempty())
				cout << "stack empty\n";
			else
				cout << "stack not empty\n";
			break;
		case 'M':
		case 'm':
			l1.visit(change);
			break;
		case 'S':
		case 's':
			l1.visit(sqr);
			break;
		}
		cout << "Pleade enter A to add a purchase order,\n"
			<< "P to empty chack a PO,\n"
			<< "S to squar all elements,\n"
			<< "M to modify or Q to quit.\n";
	}
	l1.show();
	cout << "Bye\n";
	return 0;
}
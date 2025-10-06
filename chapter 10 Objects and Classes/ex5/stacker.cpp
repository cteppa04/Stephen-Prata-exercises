#include <iostream>
#include <cctype>
#include "stack.h"

int main()
{
	using namespace std;
	static long double sum = 0;
	Stack st;
	char ch;
	customer po;
	cout << "Pleade enter A to add a purchase order,\n"
		<< "P to proccess a PO, or Q to quit.\n";
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
		case 'a': cout << "Enter a PO name to add: ";
			cin.getline(po.fullname, 35);
			cout << "Enter a PO payment to add: ";
			(cin >> po.payment).get();
			if (st.isfull())
				cout << "stack already full\n";
			else
				st.push(po);
			break;

		case 'P':
		case 'p':
			if (st.isempty())
				cout << "stack already empty\n";
			else
			{
				st.pop(po);
				cout << "PO name: " << po.fullname << ", payment: " << po.payment << " popped\n";
				cout << "Summary = " << (sum += po.payment) << std::endl;
			} 
			break;
		}
		cout << "Pleade enter A to add a purchase order,\n"
			<< "P to proccess a PO, or Q to quit.\n";
	}

	cout << "Bye\n";

	return 0;
}
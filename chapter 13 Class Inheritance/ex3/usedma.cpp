#include <iostream>
#include "dma.h"
#include <string>
#include <cstring>

const int loops = 3;

int main()
{
	using std::cout;
	using std::endl;
	using std::cin;
	
	ABC* dmas[loops];
	char* temp;
	int temprat;
	char kind;

	for (int i = 0; i < loops; i++)
	{
		cout << "Enter label: ";
		temp = new char[50];
		cin.getline(temp, 50);
		cout << "Enter rating: ";
		cin >> temprat;
		cout << "Enter 1 for baseDMA, 2 for lacksDMA, 3 for hasDMA: ";
		while (cin >> kind && (kind != '1' && kind != '2' && kind != '3'))
			cout << "Enter 1, 2 or 3: ";
		if (kind == '1')
			dmas[i] = new baseDMA(temp, temprat);
		else if (kind == '2')
		{
			char tcolor[40];
			cout << "Enter color: ";
			cin.get();
			cin.get(tcolor, 40);
			dmas[i] = new lacksDMA(tcolor, temp, temprat);
		}
		else
		{
			char* tstyle = new char[50];
			cout << "Enter style: ";
			cin.get();
			cin.get(tstyle, 50);
			dmas[i] = new hasDMA(tstyle, temp, temprat);
			delete[] tstyle;
		}
		while (cin.get() != '\n')
			continue;
		delete[] temp;
	}
	cout << endl;

	for (int i = 0; i < loops; i++)
	{
		dmas[i]->View();
		cout << endl;
	}

	for (int i = 0; i < loops; i++)
	{
		delete dmas[i];
	}

	cout << "Done.\n";

	return 0;
}
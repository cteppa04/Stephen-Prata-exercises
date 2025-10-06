#include <iostream>
#include "golf.h"

const int ArrSize = 5;

int main()
{
	using namespace std;
	int i;
	int count;
	int handicap_val = 0;

	Golf ann;
	ann.setgolf();
	ann.showgolf();
	ann.handicapf(30);
	ann.showgolf();

	cout << "Enter " << ArrSize << " players names and handicap(blank to quit):\n";
	Golf players[ArrSize];

	count = 0;
	for (i = 0; i < ArrSize; i++)
	{
		cout << "Player #" << i + 1 << ":\n";
		if (!players[i].setgolf())
			break;
		count++;
	}

	for (i = 0; i < count; i++)
	{
		cout << "Player #" << i + 1 << ":\n";
		players[i].showgolf();
	}

	cout << "Chose the player to change handicap value(0 to quit): ";
	if ((cin >> i).get() && i != 0)
	{
		cout << "Enter new value: ";
		cin >> handicap_val;
		cin.get();
		players[i-1].handicapf(handicap_val);
		for (i = 0; i < count; i++)
		{
			cout << "Player #" << i + 1 << ":\n";
			players[i].showgolf();
		}
	}

	cout << "Done!\n";

	return 0;
}
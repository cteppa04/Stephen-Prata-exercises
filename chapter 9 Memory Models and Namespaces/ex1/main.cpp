#include <iostream>
#include "golf.h"

const int ArrSize = 5;

int main()
{
	using namespace std;
	int i;
	int count;
	int handicap_val = 0;

	golf ann;
	setgolf(ann, "Ann Birdfree", 24);
	showgolf(ann);
	handicap(ann, 30);
	showgolf(ann);

	cout << "Enter " << ArrSize << " players names and handicap(blank to quit):\n";
	golf players[ArrSize];

	count = 0;
	for (i = 0; i < ArrSize; i++)
	{
		cout << "Player #" << i + 1 << ":\n";
		if (!setgolf(players[i]))
			break;
		count++;
	}

	for (i = 0; i < count; i++)
	{
		cout << "Player #" << i + 1 << ":\n";
		showgolf(players[i]);
	}

	cout << "Chose the player to change handicap value(0 to quit): ";
	if ((cin >> i).get() && i != 0) 
	{
		cout << "Enter new value: ";
		cin >> handicap_val;
		cin.get();
		handicap(players[i-1], handicap_val);
		for (i = 0; i < count; i++)
		{
			cout << "Player #" << i + 1 << ":\n";
			showgolf(players[i]);
		}
	}

	cout << "Done!\n";

	return 0;
}
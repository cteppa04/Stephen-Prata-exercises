#include <iostream>
#include <cstring>
#include "person.h"

const int SIZE = 5;

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::strchr;

	Person* persons[SIZE];
	int count;

	std::string fname;
	std::string sname;
	double gdraw;
	int notches;

	for (count = 0; count < SIZE; count++)
	{
		cout << "Enter a type of person:\n";
		cout << "g: Gunslinger,    p: PockerPlayer,    b: BadDude,    q: quit\n";
		char ch;
		cin >> ch;  
		cin.get();
		while (strchr("gpbq", ch) == 0)
		{
			cout << "Wrong input, try again: ";
			cin >> ch;
			cin.get();
		}
		if (ch == 'q')
			break;
		cout << "Enter first name: ";
		cin >> fname;
		cout << "Enter second name: ";
		cin >> sname;
		switch (ch)
		{
		case 'g': 
			cout << "Enter guns draw: ";
			cin >> gdraw;
			cout << "Enter guns notches: ";
			cin >> notches;
			persons[count] = new Gunslinger(fname, sname, gdraw, notches);
			break;
		case 'p': 
			persons[count] = new PockerPlayer(sname, fname);
			break;
		case 'b': 
			cout << "Enter guns draw: ";
			cin >> gdraw;
			cout << "Enter guns notches: ";
			cin >> notches;
			persons[count] = new BadDude(fname, sname, gdraw, notches);
			break;
		}
		cin.get();
	}

	if(count > 0)
		cout << "\nHere is a persons:\n\n";
	for (int i = 0; i < count; i++)
	{
		persons[i]->Show();
		cout << endl;
	}

	for (int i = 0; i < count; i++)
	{
		delete persons[i];
	}

	cout << "Bye.\n";

	return 0;
}

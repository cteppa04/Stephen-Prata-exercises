#include <iostream>
using namespace std;
using std::cout;
#include "emp.h"
#include <fstream>

const char* file = "file.txt";
const int MAX = 10;

void selection_menu();

int main(void)
{
	employee* pc[MAX];

	int index;
	int i;
	int classtype;

	//First read from file
	ifstream fin(file);
	if (fin.is_open())
	{
		cout << "Here are the current employee list:\n";

		index = 0;
		while ((fin >> classtype).get() && index < MAX && !fin.eof())
		{
			switch (classtype)
			{
			case Employee: pc[index] = new employee;
				pc[index++]->getAll(fin);
				break;
			case Manager: pc[index] = new manager;
				pc[index++]->getAll(fin);
				break;
			case Fink: pc[index] = new fink;
				pc[index++]->getAll(fin);
				break;
			case Highfink: pc[index] = new highfink;
				pc[index++]->getAll(fin);
				break;
			default:
				break;
			}
		}
		for (i = 0; i < index; i++)
		{
			std::cout << "\nEmployee number " << i + 1 << ":\n";
			pc[i]->ShowAll();
			delete pc[i];
		}

		fin.close();

		cout << endl;
	}


	//Writing to file
	ofstream fout(file, ios_base::out | ios_base::app);
	if (!fout.is_open())
	{
		cerr << "Can't open " << file << " file.\n";
		exit(EXIT_FAILURE);
	}
	cout << "Enter data:\n";
	selection_menu();
	index = 0;
	while ((cin >> classtype).get() && classtype != 5 && index < MAX)
	{
		switch (classtype)
		{
		case Employee: pc[index] = new employee;
			pc[index++]->SetAll();
			selection_menu();
			break;
	
		case Manager: pc[index] = new manager;
			pc[index++]->SetAll();
			selection_menu();
			break;

		case Fink: pc[index] = new fink;
			pc[index++]->SetAll();
			selection_menu();
			break;

		case Highfink: pc[index] = new highfink;
			pc[index++]->SetAll();
			selection_menu();
			break;

		default: cout << "Wrong input try again.\n";
			break;
		}
	}
	for (i = 0; i < index; i++)
	{
		pc[i]->writeAll(fout);
		delete pc[i];
	}

	fout.close();


	//Second reading from file
	fin.clear();
	fin.open(file);
	if (fin.is_open())
	{
		cout << "Here are the new employee list:\n";
		index = 0;
		while ((fin >> classtype).get() && index < MAX && !fin.eof())
		{
			switch (classtype)
			{
			case Employee: pc[index] = new employee;
				pc[index++]->getAll(fin);
				break;
			case Manager: pc[index] = new manager;
				pc[index++]->getAll(fin);
				break;
			case Fink: pc[index] = new fink;
				pc[index++]->getAll(fin);
				break;
			case Highfink: pc[index] = new highfink;
				pc[index++]->getAll(fin);
				break;
			default:
				break;
			}
		}
		for (i = 0; i < index; i++)
		{
			cout << endl;
			pc[i]->ShowAll();
			delete pc[i];
		}

		fin.close();
	}
	
	cout << "\nDone.\n";

	return 0;
}

void selection_menu()
{
	cout << "\nChoose a employee type:\n";
	cout << "1) Employe\t2) Manager\n";
	cout << "3) Fink   \t4) Highfink\n";
	cout << "5) quit\n";
}
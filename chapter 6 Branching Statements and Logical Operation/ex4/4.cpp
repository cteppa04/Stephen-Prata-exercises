#include <iostream>

const int str_size = 40;
const int count_workers = 4;

struct bop {
	const char *full_name;
	char title[str_size];
	char bop_name[str_size];
	int preference;
};

int main()
{
	using namespace std;

	bop workers[count_workers] = {
		{"Richard Morison", "BBRLN", "Richardo Milos", 0},
		{"Gringo Lubexo", "NLM", "Gudinio", 1},
		{"Defaul Antonio", "WP", "DE coco", 2},
		{"Harrier Du Bois", "Oficcer", "Disco", 2}
	};

	cout << "a. display by name		b. display by titel\n"
		"c. display by bopname		d. display by preference\n"
		"q. quit\n";


	cout << "Enter your chois: ";
	char ch;
	cin >> ch;

	while (ch != 'q')
	{
		for (int i = 0; i < count_workers; i++)
		{
			switch (ch)
			{
			case 'a': cout << workers[i].full_name << endl;
				break;
			case 'b': cout << workers[i].title << endl;
				break;
			case 'c': cout << workers[i].bop_name << endl;
				break;
			case 'd':
				switch (workers[i].preference)
				{
				case 0: cout << workers[i].full_name << endl;
					break;
				case 1: cout << workers[i].title << endl;
					break;
				case 2: cout << workers[i].bop_name << endl;
					break;
				}
				break;
			}
		}
		cin >> ch;
	}
	cout << "Bye!\n";
	

	return 0;
}
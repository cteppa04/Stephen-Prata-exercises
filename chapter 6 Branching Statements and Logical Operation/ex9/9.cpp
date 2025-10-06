#include <iostream>
#include <fstream>

struct patriarh
{
	char name[20];
	double donate;
};

int main()
{
	using namespace std;

	ifstream file("file.txt");

	int count;
	file >> count;
	int array_count = 0;
	patriarh* all = new patriarh[count];
	for (int i = 0; i < count; i++)
	{
		file.get();
		file.getline(all[i].name, 20);
		file >> all[i].donate;
	}

	cout << "GRAND PATRONS:\n";
	for (int i = 0; i < count; i++)
	{
		if (all[i].donate >= 10000)
		{
			cout <<  all[i].name << "	" << all[i].donate << endl;
			array_count++;
		}
	}
	if (array_count == 0)
		cout << "none\n";
	array_count = 0;

	cout << "\nPATRONS:\n";
	for (int i = 0; i < count; i++)
	{
		if (all[i].donate < 10000)
		{
			cout << all[i].name << "	" << all[i].donate << endl;
			array_count++;
		}
	}
	if (array_count == 0)
		cout << "none\n";
	array_count = 0;

	delete[] all;

	file.close();

	return 0;
}
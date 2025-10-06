#include <iostream>

struct patriarh
{
	char name[20];
	double donate;
};

int main()
{
	using namespace std;

	cout << "Enter hove mutch patrons are: ";
	int count;
	cin >> count;
	int array_count = 0;
	patriarh* all = new patriarh[count];
	for (int i = 0; i < count; i++)
	{
		cout << "Enter patron #" << i + 1 << " name: ";
		cin.get();
		cin.getline(all[i].name, 20);
		cout << "Enter patron #" << i + 1 << " donate: ";
		cin >> all[i].donate;
	}

	cout << "\nGRAND PATRONS:\n";
	for (int i = 0; i < count; i++)
	{
		if (all[i].donate >= 10000)
		{
			cout << i + 1 << ": " << all[i].name << "	" << all[i].donate << endl;
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
			cout << i + 1 << ": " << all[i].name << "	" << all[i].donate << endl;
			array_count++;
		}
	}
	if (array_count == 0)
		cout << "none\n";
	array_count = 0;

	delete[] all;

	return 0;
}
#include <iostream>

struct car
{
	char name[20];
	int year;
};

int main()
{
	using namespace std;

	cout << "How much cars: ";
	int count;
	cin >> count;
	cin.get();

	car* mach = new car[count];

	for (int i = 0; i < count; ++i)
	{
		cout << "Car #" << i + 1 << ":\n";
		cout << "Enter car name: ";
		cin.getline(mach[i].name,19);
		cout << "Enter relese year: ";
		cin >> mach[i].year;
		cin.get();
	}

	cout << "Your colection:\n";

	for (int i = 0; i < count; ++i)
	{
		cout << mach[i].year << " " << mach[i].name << endl;
	}

	return 0;
}
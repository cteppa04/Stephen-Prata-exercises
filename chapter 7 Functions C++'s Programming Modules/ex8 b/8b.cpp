#include <iostream>

const int Seasons = 4;
const char* Snames[Seasons] = { "Spring", "Summer", "Fall", "Winter" };

struct expenses
{
	double price[Seasons];
};

void fill(expenses* pa);
void show(const expenses* da);

int main()
{
	expenses rere;
	fill(&rere);
	show(&rere);

	return 0;
}

void fill(expenses* pa)
{
	using namespace std;
	for (int i = 0; i < Seasons; ++i)
	{
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> pa->price[i];
	}
}

void show(const expenses* da)
{
	using namespace std;
	double total = 0;
	cout << "EXPENSES\n";
	for (int i = 0; i < Seasons; ++i)
	{
		cout << Snames[i] << ": $" << da->price[i] << endl;
		total += (*da).price[i];
	}
	cout << "Total Expenses: $" << total << endl;
}
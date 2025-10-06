#include <iostream>

struct CandyBar
{
	char name[20];
	double weight;
	int calorie;
 };

int main()
{
	using namespace std;

	CandyBar snack =
	{
		"Mocha Munch",
		2.3,
		350
	};

	cout << "Name: " << snack.name << ", weigt: " << snack.weight << ", calorie: " << snack.calorie << endl;

	return 0;
}
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

	CandyBar snack[3] =
	{
		{"Gringo", 1.1, 100},
		{"fugo", 2.2, 200},
		{"miomo", 3.3, 300}
	};

	cout << "1:\n";
	cout << "Name: " << snack[0].name << ", weight: " << snack[0].weight << ", calorie: " << snack[0].calorie << endl;

	cout << "2:\n";
	cout << "Name: " << snack[1].name << ", weight: " << snack[1].weight << ", calorie: " << snack[1].calorie << endl;

	cout << "3:\n";
	cout << "Name: " << snack[2].name << ", weight: " << snack[2].weight << ", calorie: " << snack[2].calorie << endl;

	return 0;
}
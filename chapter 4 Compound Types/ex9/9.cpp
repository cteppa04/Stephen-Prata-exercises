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

	CandyBar* candy = new CandyBar[3];
	*candy = {
		"warm", 12.2, 300
	};
	candy[1] = {
		"grig", 30, 100
	};
	*(candy + 2) = {
		"fugo", 10, 150
	};

	cout << "1:\n";
	cout << "name: " << candy->name << ", weight: " << candy->weight << ", calorie: " << candy->calorie << endl;
	
	cout << "1:\n";
	cout << "name: " << (*candy).name << ", weight: " << (*candy).weight << ", calorie: " << (*candy).calorie << endl;
	

	cout << "2:\n";
	cout << "name: " << candy[1].name << ", weight: " << candy[1].weight << ", calorie: " << candy[1].calorie << endl;

	cout << "3:\n";
	cout << "name: " << (candy + 2)->name << ", weight: " << (candy + 2)->weight << ", calorie: " << (candy + 2)->calorie << endl;
 
	delete[] candy;
}
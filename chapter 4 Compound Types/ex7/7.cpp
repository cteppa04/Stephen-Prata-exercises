#include <iostream>

struct william_wingate 
{
	char comp_name[20];
	int diameter;
	double weight;
};

int main()
{
	using namespace std;

	william_wingate pizza1;
	cout << "Enter pizza's company name: ";
	cin.getline(pizza1.comp_name, 20);
	cout << "Enter diameter of pizza: ";
	cin >> pizza1.diameter;
	cout << "Enter pizza's weight: ";
	cin >> pizza1.weight;

	cout << "Name: " << pizza1.comp_name << ", diameter: " << pizza1.diameter << ", weight: " << pizza1.weight << endl;

	return 0;
}
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

	william_wingate* pizza1 = new william_wingate;
	cout << "Enter pizza's diameter: ";
	(cin >> pizza1->diameter).get();
	cout << "Enter pizza's company name: ";
	cin.getline(pizza1->comp_name, 20);
	cout << "Enter pizza's weight: ";
	cin >> pizza1->weight;

	cout << "Company name: " << pizza1->comp_name << ", diameter: " << pizza1->diameter << ", weight: " << pizza1->weight << endl;

	delete pizza1;

	return 0;
}
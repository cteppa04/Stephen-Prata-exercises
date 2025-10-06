#include <iostream>

double avg_harm(int x, int y);

int main()
{
	using namespace std;
	cout << "Enter pare of integers: ";
	int x, y;
	while (cin >> x && x != 0 && cin >> y && y != 0)
	{
		cout << "Harmony = " << avg_harm(x, y) << "\nEnter anoter numbers: ";
	}
	cout << "Done\n";
	return 0;
}

double avg_harm(int x, int y)
{
	return 2.0 * x * y / (x + y);
}
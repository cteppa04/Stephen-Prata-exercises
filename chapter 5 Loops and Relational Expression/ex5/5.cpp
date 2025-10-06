#include <iostream>

int main()
{
	using namespace std;

	const int mounths = 12;
	const char* mounth[mounths] =
	{
		"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"
	};
	int books[mounths];
	int sum = 0;

	cout << "Enter book sells:\n";
	for (int i = 0; i < mounths; i++)
	{
		cout << mounth[i] << ": ";
		cin >> books[i];
	}

	for (int x : books)
	{
		sum += x;
	}

	cout << "Year sallary = " << sum << endl;

	return 0;
}
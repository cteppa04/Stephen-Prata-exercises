#include <iostream>
#include <fstream>
#include <string>

int main()
{
	using namespace std;

	int count = 0;
	ifstream file;
	
	cout << "Enter file name: ";
	string name;
	cin >> name;

	file.open(name);

	char ch;

	if (file.is_open())
		cout << "Success!\n";
	else
		cout << "Error!\n";

	file.get(ch);
	while (file.good())
	{
		count++;
		file.get(ch);
	}


	cout << count << " characters.\n";

	file.close();

	return 0;
}
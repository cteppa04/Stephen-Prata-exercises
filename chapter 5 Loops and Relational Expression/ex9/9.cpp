#include <iostream>
#include <string>

int main()
{
	using namespace std;

	cout << "Enter words(enter done to end)" << endl;
	string word;
	cin >> word;
	int count = 0;

	while (word != "done")
	{
		++count;
		cin >> word;
	}

	cout << "You entered " << count << " words";

	return 0;
}
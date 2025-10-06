#include <iostream>
#include <cstring>

int main()
{
	using namespace std;

	cout << "Enter words(to end enter \"done\")" << endl;
	
	int count = 0;
	char word[20];

	for (cin >> word; strcmp(word, "done"); ++count)
	{
		cin >> word;
	}

	cout << "You entered " << count << " words.\n";

	return 0;
}
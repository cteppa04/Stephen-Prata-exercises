#include <iostream>
#include <cctype>

int main()
{
	const int diff = int('A' - 'a');
	using namespace std;

	char ch;
	cin.get(ch);

	while (ch != '@')
	{
		if (isupper(ch))
			cout << char(ch - diff);
		else if (islower(ch))
			cout << char(ch + diff);
		else if (isdigit(ch))
		{
			cin.get(ch);
			continue;
		}
		else
			cout << ch;
		cin.get(ch);
	}

	return 0;
}
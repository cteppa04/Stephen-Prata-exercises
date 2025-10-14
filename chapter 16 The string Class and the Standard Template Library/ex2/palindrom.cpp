#include <iostream>
#include <string>

bool palindrom(const std::string& str);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	cout << "Enter a string to chech is it a palindrom(blank to quit): ";
	std::string pal;
	while (getline(cin, pal) && pal != "")
	{
		if (palindrom(pal))
		{
			cout << "The word \"" << pal << "\" is palindrom\n";
		}
		else
		{
			cout << "The word \"" << pal << "\" is not palindrom\n";
		}
		cout << "Enter another word(blank to quit): ";
	}
	cout << "Bye\n";

	return 0;
}

bool palindrom(const std::string& str)
{
	std::string strCopy = str;
	std::string::iterator it0, it1, it2;
	
	for (it0 = strCopy.begin(); it0 != strCopy.end(); )
	{
		if (isalpha(*it0) || isdigit(*it0))
		{
			if (!islower(*it0))
				*it0 = tolower(char(*it0));
			it0++;
		}
		else
		{
			strCopy.erase(it0);
		}
	}
	for (it1 = strCopy.begin(), it2 = strCopy.end() - 1; it1 < it2; it1++, it2--)
	{
		if (*it1 != *it2)
			return false;
	}
	return true;
}
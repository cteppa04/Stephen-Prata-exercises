#include <iostream>
#include <string>

bool palindrom(std::string& str);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	cout << "Enter a string to chech is it a palindrom(quit to quit): ";
	std::string pal;
	while (getline(cin, pal) && pal != "quit")
	{
		if (palindrom(pal))
		{
			cout << "The word " << pal << " is palindrom\n";
		}
		else
		{
			cout << "The word " << pal << " is not palindrom\n";
		}
		cout << "Enter another word(quit to quit): ";
	}
	cout << "Bye\n";
	
	return 0;
}

bool palindrom(std::string& str)
{
	/*
	int it1, it2;
	for (it1 = 0, it2 = str.length() - 1; it1 < it2; it1++, it2--)
	{
		if (str[it1] != str[it2])
			return false;
	}
	*/
	std::string::iterator it1, it2;
	for (it1 = str.begin(), it2 = str.end() - 1; it1 < it2; it1++, it2--)
	{
		if (*it1 != *it2)
			return false;
	}
	return true;
}
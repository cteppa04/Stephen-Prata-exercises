#include <iostream>
#include <string>

void toup(std::string& str);

int main()
{
	std::string str;
	std::cout << "Enter a string (q to quit): ";
	while (getline(std::cin, str) && str != "q")
	{
		toup(str);
	}
	std::cout << "Bye.\n";
	return 0;
}

void toup(std::string& str)
{
	using namespace std;
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = toupper(str[i]);
		cout << str[i];
	}
	cout << endl << "Next string (q to quit): ";
}
#include <iostream>
#include <string>

int main()
{
	using namespace std;

	string first_name;
	string last_name;
	string finish;

	cout << "Enter your first name: ";
	getline(cin, first_name);
	cout << "Enter your last name: ";
	getline(cin, last_name);

	finish = last_name + ", " + first_name;
	cout << "Here's the information in a single string: " << finish << endl;

	return 0;
}
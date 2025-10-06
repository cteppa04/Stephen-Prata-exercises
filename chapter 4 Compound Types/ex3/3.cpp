#include <iostream>
#include <cstring>

int main()
{
	using namespace std;

	const char array_size = 20;
	char first_name[array_size];
	char last_name[array_size];
	const int finish_size = 2 * array_size + 1;
	char finish[finish_size];

	cout << "Enter your first name: ";
	cin.getline(first_name, array_size);
	cout << "Enter your last name: ";
	cin.getline(last_name, array_size);
	strcpy_s(finish, finish_size, last_name);
	strcat_s(finish, finish_size, ", ");
	strcat_s(finish, finish_size, first_name);

	cout << "Here's the information in a single string: " << finish << endl;;

	return 0;
}
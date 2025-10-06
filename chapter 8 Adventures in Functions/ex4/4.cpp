#include <iostream>
using namespace std;
#include <cstring>

struct stringy {
	char* str;
	int ct;
};

void set(stringy& stru, char* testing);
void show(const stringy& stru, int n = 1);
void show(const char* str, int n = 1);

int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";
	set(beany, testing);
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");
	delete[] beany.str;
	return 0;
}

void set(stringy& stru, char* testing)
{
	char* copy = new char[strlen(testing) + 1];
	stru.str = copy;
	strcpy_s(copy, strlen(testing) + 1, testing);
	stru.ct = strlen(stru.str);
}

void show(const stringy& stru, int n)
{
	for (int i = 0; i < n; i++)
		cout << stru.str << endl;
	cout << stru.ct << endl;
}

void show(const char* str, int n)
{
	for (int i = 0; i < n; i++)
		cout << str << endl;
}
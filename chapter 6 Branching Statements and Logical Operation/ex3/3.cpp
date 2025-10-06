#include <iostream>

void wrong_enter(char);

int main()
{
	using namespace std;

	cout << "Please enter one of the following choise:\n"
		"c) carnivore	p) pianist\n"
		"t) tree		g) game\n";

	char ch;
	
	cin >> ch;

	while (ch != 'c' and ch != 'p' and ch != 't' and ch != 'g')
	{
		cout << "Please enter a c, p, t, or g: ";
		cin >> ch;
	}

	switch (ch)
	{
	case 'c': cout << "Carnivore el favore\n";
		break;
	case 'p': cout << "Ludwig don't hear\n";
		break;
	case 't': cout << "A maple is a tree\n";
		break;
	case 'g': cout << "You wanna play? Let's play!\n";
		break;
	}

	return 0;
}
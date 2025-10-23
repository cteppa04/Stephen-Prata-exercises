#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
	using namespace std;

	if (argc == 1)
	{
		cerr << "Bad cmd input.\n";
		exit(EXIT_FAILURE);
	}

	ofstream fout(argv[1]);
	if (!fout.is_open())
	{
		cerr << "Can't open file.\n";
		exit(EXIT_FAILURE);
	}

	cout << "Enter characters to copy: ";
	char ch;
	while ((ch = cin.get()) != EOF)
	{
		fout << ch;
	}

	fout.close();

	cout << "Done.\n";

	return 0;
}
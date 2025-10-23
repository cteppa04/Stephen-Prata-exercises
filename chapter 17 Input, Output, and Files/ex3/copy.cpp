#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
	using namespace std;

	if (argc != 3)
	{
		cerr << "Bad cmd arguments.\n";
		exit(EXIT_FAILURE);
	}

	ifstream fin(argv[1]);
	if (!fin.is_open())
	{
		cerr << "Can't open input file.\n";
		exit(EXIT_FAILURE);
	}

	ofstream fout(argv[2]);
	if (!fout.is_open())
	{
		cerr << "Can't open output file.\n";
		exit(EXIT_FAILURE);
	}

	char ch;
	while ((ch = fin.get()) != EOF)
	{
		fout << ch;
	}

	fin.close();
	fout.close();

	cout << "Done.\n";

	return 0;
}
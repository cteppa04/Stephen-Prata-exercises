#include <iostream>
#include <fstream>

const char* input1 = "input1.txt";
const char* input2 = "input2.txt";
const char* output = "output.txt";

int main()
{
	using namespace std;

	ifstream fin1(input1);
	if (!fin1.is_open())
	{
		cerr << "Can't open input1 file.\n";
		exit(EXIT_FAILURE);
	}

	ifstream fin2(input2);
	if (!fin2.is_open())
	{
		cerr << "Can't open input2 file.\n";
		exit(EXIT_FAILURE);
	}

	ofstream fout(output);
	if (!fout.is_open())
	{
		cerr << "Can't open output file.\n";
		exit(EXIT_FAILURE);
	}

	char ch;
	while (!fin1.eof() || !fin2.eof())
	{
		if (!fin1.eof())
		{
			while (fin1.get(ch) && ch != '\n')
			{
				fout << ch;
			}
		}
		if (!fin2.eof())
		{
			while (fin2.get(ch) && ch != '\n')
			{
				fout << ch; 
			}
		}
		fout << '\n';
	}

	fin1.close();
	fin2.close();
	fout.close();

	cout << "Done.\n";

	return 0;
}
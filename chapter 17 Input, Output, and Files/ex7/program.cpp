#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "store.h"

void ShowStr(const std::string& str);

void GetStrs(std::ifstream& is, std::vector<std::string>& vect);

int main()
{
	using namespace std;
	vector<string> vostr;
	string temp;

	cout << "Enter string (empty line to quit):\n";
	while (getline(cin, temp) && temp[0] != '\0')
		vostr.push_back(temp);
	cout << "Here is your input.\n";
	for_each(vostr.begin(), vostr.end(), ShowStr);

	ofstream fout("strings.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();

	vector<string> vistr;
	ifstream fin("strings.dat", ios_base::in | ios_base::binary);
	if (!fin.is_open())
	{
		cerr << "Could not open file for input.\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);
	cout << "\nHere are the string read from the file:\n";
	for_each(vistr.begin(), vistr.end(), ShowStr);

	return 0;
}

void ShowStr(const std::string& str)
{
	std::cout << str << "\n";
}

void GetStrs(std::ifstream& is, std::vector<std::string>& vect)
{
	int len;
	while (is.read((char*)&len, sizeof(std::size_t)))
	{
		std::string temp;
		char ch;
		for (int i = 0; i < len; i++)
		{
			is.read((char*)&ch, sizeof(char));
			temp += ch;
		}
		vect.push_back(temp);
	}
}
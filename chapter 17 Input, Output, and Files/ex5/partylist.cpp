#include <iostream>
#include <fstream>
#include <list>
#include <string>

int main()
{
	std::ifstream matin("mat.dat");
	if (!matin.is_open())
	{
		std::cerr << "Can't open mat.dat\n";
		exit(EXIT_FAILURE);
	}

	std::ifstream patin("pat.dat");
	if (!patin.is_open())
	{
		std::cerr << "Can't open pat.dat\n";
		exit(EXIT_FAILURE);
	}

	std::ofstream matnpatout("matnpat.dat");
	if (!matnpatout.is_open())
	{
		std::cerr << "Can't open matnpat.dat\n";
		exit(EXIT_FAILURE);
	}

	std::list<std::string> Mat;
	std::list<std::string> Pat;
	std::list<std::string> All;
	std::string temp;

	while (!matin.eof())
	{
		getline(matin, temp);
		Mat.push_back(temp);
	}
	matin.close();
	Mat.sort();
	std::cout << "Mat's friends:\n";
	for (auto it = Mat.begin(); it != Mat.end(); it++)
	{
		std::cout << *it << "    ";
		All.push_back(*it);
	}
	std::cout << std::endl;

	while (!patin.eof())
	{
		getline(patin, temp);
		Pat.push_back(temp);
	}
	patin.close();
	std::cout << "Pat's friends:\n";
	for (auto it = Pat.begin(); it != Pat.end(); it++)
	{
		std::cout << *it << "    ";
		All.push_back(*it);
	}
	Pat.sort();
	std::cout << std::endl;

	All.sort();
	All.unique();
	for (std::list<std::string>::iterator it = All.begin(); it != All.end(); it++)
	{
		matnpatout << *it << std::endl;
	}
	matnpatout.close();

	std::cout << "Done.\n";

	return 0;
}
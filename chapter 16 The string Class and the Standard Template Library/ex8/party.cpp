#include <iostream>
#include <list>
#include <string>

int main()
{
	std::list<std::string> Mat;
	std::list<std::string> Pat;
	std::list<std::string> All;
	std::string temp;

	std::cout << "Enter Mat's friends list(q to quit): ";
	while (std::cin >> temp && temp != "q")
	{
		Mat.push_back(temp);
	}
	Mat.sort();
	std::cout << "Sorted Mat's friends list:\n";
	for (auto it = Mat.begin(); it != Mat.end(); it++)
	{
		std::cout << *it << "    ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "Enter Pat's friends list(q to quit): ";
	while (std::cin >> temp && temp != "q")
	{
		Pat.push_back(temp);
	}
	Pat.sort();
	std::cout << "Sorted Mat's friends list:\n";
	for (auto it = Pat.begin(); it != Pat.end(); it++)
	{
		std::cout << *it << "    ";
	}
	std::cout << std::endl << std::endl;

	for (std::list<std::string>::iterator it = Mat.begin(); it != Mat.end(); it++)
	{
		All.push_back(*it);
	}
	for (auto it = Pat.begin(); it != Pat.end(); it++)
	{
		All.push_back(*it);
	}
	All.sort();
	All.unique();

	std::cout << "List of all friends:\n";
	for (auto it = All.begin(); it != All.end(); it++)
	{
		std::cout << *it << "    ";
	}
	std::cout << std::endl;

	return 0;
}

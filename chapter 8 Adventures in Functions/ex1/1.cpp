#include <iostream>

void print(const char* str, int n = 0);

int main()
{
	using namespace std;
	print("one");
	print("two");
	print("three", 1);

	return 0;
}

void print(const char* str, int n)
{
	static int count = 0;
	if (n == 0)
		std::cout << str << std::endl;
	else
		for (int i = 0; i < count; i++)
			std::cout << str << std::endl;
	count++;
}
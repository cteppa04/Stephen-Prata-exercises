#include <iostream>

int main()
{
	std::cout << "Enter a line($ to quir): ";
	int count = 0;
	while (std::cin.get() != '$')
	{
		count++;
		if (std::cin.peek() == '$')
			break;
	}
	std::cout << "Number of characters = " << count << ", next character is " << char(std::cin.get()) << std::endl;

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

std::vector<int> Lotto(int range, int n);

int main()
{
	srand(time(0));
	std::vector<int> winner;
	char yn = 'y';
	while (yn == 'y')
	{
		std::cout << "Enter the range of numbers: ";
		int range;
		std::cin >> range;
		std::cout << "Enter the number of digits: ";
		int number;
		std::cin >> number;
		winner = Lotto(range, number);
		std::cout << "Winning lotto: ";
		for (int i = 0; i < number; i++)
		{
			std::cout << winner[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "Wanna play one more time?(y/n): ";
		std::cin >> yn;
	}
	std::cout << "Bye\n";
	return 0;
}

std::vector<int> Lotto(int range, int n)
{
	std::vector<int> lotto;
	for (int i = 1; i <= range; i++)
	{
		lotto.push_back(i);
	}
	std::random_shuffle(lotto.begin(), lotto.end());
	lotto.erase(lotto.begin() + n, lotto.end());
	return lotto;
}
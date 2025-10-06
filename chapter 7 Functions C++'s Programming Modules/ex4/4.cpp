#include <iostream>

long double probability(unsigned num1, unsigned picks);

int main()
{
	using namespace std;
	double total, choices, meganum, limit;
	cout << "Enter the total number of choices on the game card and\n"
		<< "the number of picks allowed:\n";
	while ((cin >> total >> choices) && choices <= total) 
	{
		cout << "Enter the total number of choices on the game card and\n"
			<< "the number of picks allowed for the Mega Number:\n";
		if ((cin >> limit >> meganum) && limit >= meganum)
		{
			cout << "You have one chance in ";
			cout << probability(total, choices) * probability(limit, meganum);
			cout << "of wining. \n";
		}
		cout << "Next two numbers(q to quit):\n";
	}
	cout << "Done" << endl;
	return 0;
}

long double probability(unsigned num, unsigned picks)
{
	long double result = 1;
	long double n;
	unsigned p;
	for (n = num, p = picks ; p > 0; n--, p--)
	{
		result = result * n / p;
	}
	return result;
}
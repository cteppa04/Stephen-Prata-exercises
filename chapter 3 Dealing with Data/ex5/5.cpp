#include <iostream>
#include <vector>

int main()
{
	using namespace std;

	long long world_pop, country_pop;
	double cof;

	cout << "Enter the world's population: ";
	cin >> world_pop;
	cout << "Enter the country population: ";
	cin >> country_pop;
	
	cof = double(country_pop) / double (world_pop) * 100;

	cout << "The population of country is " << cof << "% of the world population.";

	return 0;
} 
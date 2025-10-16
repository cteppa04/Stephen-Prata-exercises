#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <algorithm>


int main()
{
	int SIZE;
	std::srand(time(0));
	clock_t start;
	clock_t finish;

	std::cout << "Enter size of array: ";
	std::cin >> SIZE;
	
	std::vector<int> vi0(SIZE);
	for (int i = 0; i < vi0.size(); i++)
		vi0[i] = rand() % INT_MAX;

	std::vector<int> vi(SIZE);
	std::copy(vi0.begin(), vi0.end(), vi.begin());
	std::list<int> li(SIZE);
	std::copy(vi0.begin(), vi0.end(), li.begin());

	std::cout << "Array size: " << SIZE << std::endl;
	
	start = clock();
	std::sort(vi.begin(), vi.end());
	finish = clock();
	std::cout << "Time to sort vector array: " << (double)(finish - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

	start = clock();
	li.sort();
	finish = clock();
	std::cout << "Time to sort list array: " << (double)(finish - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

	return 0;
}
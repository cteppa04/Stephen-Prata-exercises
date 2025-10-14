#include <iostream>
#include <algorithm>
#include <string>

const int SIZE = 7;

template <class T>
int reduce(T ar[], int n);

int main()
{
	int newSize;
	
	long arrayL[SIZE] = { 1, 4, 1, 33, 2, 1, 9 };
	std::cout << "Array elements: ";
	newSize = reduce(arrayL, SIZE);
	for (int i = 0; i < newSize; i++)
	{
		std::cout << arrayL[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Elements count: " << newSize << std::endl;

	std::string arrayS[SIZE] = { "long", "reference", "dongle", "long", "dodo", "long", "bingo" };
	std::cout << "Array elements: ";
	newSize = reduce(arrayS, SIZE);
	for (int i = 0; i < newSize; i++)
	{
		std::cout << arrayS[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Element count: " << newSize << std::endl;

	return 0;
}

template <class T>
int reduce(T ar[], int n)
{
	T temp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (ar[j] > ar[j + 1])
			{
				temp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = temp;
			}
		}
	}
	T* end = std::unique(ar, ar + n);
	return end - ar;
}
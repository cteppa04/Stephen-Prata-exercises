#include <iostream>
#include <algorithm>

const int SIZE = 6;

int reduce(long ar[], int n);

int main()
{
	int newSize;
	long array[SIZE] = { 1, 4, 1, 33, 2, 1 };
	std::cout << "Array elements: ";
	newSize = reduce(array, SIZE);
	for (int i = 0; i < newSize; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Elements count: " << newSize << std::endl;
	return 0;
}

int reduce(long ar[], int n)
{
	int i;
	long temp;
	for (i = 0; i < n - 1; i++)
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
	i++;
	long* end = std::unique(ar, ar + i);
	return end - ar;
}

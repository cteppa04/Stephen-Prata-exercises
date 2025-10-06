#include <iostream>

template<typename T>
T max(T arr[]);

int main()
{
	double arr1[5] = { 1.1,44.1,3.3,4.4,5.5 };
	int arr2[5] = { 1,6,3,4,5 };
	std::cout << max(arr1) << std::endl;
	std::cout << max(arr2) << std::endl;
}

template<typename T>
T max(T arr[])
{
	T temp = arr[0];
	for (int i = 1; i < 5; i++)
		if (arr[i] > temp)
			temp = arr[i];
	return temp;
}
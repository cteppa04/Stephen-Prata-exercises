#include <iostream>
#include <cstring>

template <typename T>
T maxn(T arr[], int n);

template <> const char* maxn(const char* arr[], int n);

int main()
{
	int int_arr[6] = { 1,3,34,12,33,2 };
	double double_arr[4] = { 1.23, 64.3, 12, 22.3 };
	const char* char_arr[] = { "abraha", "dres", "freferd" };

	std::cout << maxn(int_arr, 6) << std::endl;
	std::cout << maxn(double_arr, 4) << std::endl;
	std::cout << maxn(char_arr, 3) << std::endl;

	return 0;
}

template <typename T>
T maxn(T arr[], int n)
{
	T max = arr[0];
	for (int i = 1; i < n; i++)
		if (max < arr[i])
			max = arr[i];
	return max;
}

template <>
const char* maxn(const char* arr[], int n)
{
	const char* max = arr[0];
	for (int i = 1; i < n; i++)
		if (strlen(max) < strlen(arr[i]))
			max = arr[i];
	return max;
}
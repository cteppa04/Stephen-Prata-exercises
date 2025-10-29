#include <iostream>

template <typename T>
long double sum_values(const T& x)
{
	return (long double) x;
}

template <typename T, typename... Args>
long double sum_values(const T& x, const Args&... args)
{
	return (long double)x + sum_values(args...);
}

int main()
{
	long double sum = sum_values(31.4, 12L, 90, 67.11f, -83.42);
	std::cout << sum << std::endl;

	return 0;
}

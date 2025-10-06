#include <iostream>
#include <cstring>
#include <new>

const int ArraySize = 2;

struct chaff
{
	char dross[20];
	int slag;
};

char buffer[ArraySize * sizeof(chaff)];

void fill(chaff st[], int size);
void show(const chaff st[], int size);

int main()
{
	chaff* arr1 = new (buffer) chaff[ArraySize];
	fill(arr1, ArraySize);
	show(arr1, ArraySize);
	chaff* arr2 = new chaff[ArraySize];
	fill(arr2, ArraySize);
	show(arr2, ArraySize);
	delete[] arr1;
	return 0;
	
}

void fill(chaff st[], int size)
{
	char temp[20];
	int slag;
	for (int i = 0; i < size; i++)
	{
		std::cout << "Chaff #" << i + 1 << ":\n";
		std::cout << "Enter dross: ";
		if (!std::cin.get(temp, 20))
		{
			std::cin.clear();
			break;
		}
		while (std::cin.get() != '\n')
			continue;
		strcpy_s(st[i].dross, 20, temp);
		std::cout << "Enter slag: ";
		std::cin >> slag;
		std::cin.get();
		st[i].slag = slag;
	}
}

void show(const chaff st[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "Chaff #" << i + 1 << ":\n";
		std::cout << "Dross: " << st[i].dross << ",   Slag: " << st[i].slag << std::endl;
	}
}
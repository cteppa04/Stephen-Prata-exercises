#include <iostream>

struct CandyBar
{
	const char* name;
	double weight;
	int calories;
};

void fill(CandyBar& cb, const char* name = "Millennium Munch", double weight = 2.85, int calories = 350);
void show(const CandyBar& cb);

int main()
{
	CandyBar bixby;
	fill(bixby);
	show(bixby);
	CandyBar arrr;
	fill(arrr, "DFS", 33.3, 222);
	show(arrr);
	return 0;
}

void fill(CandyBar& cb, const char* name, double weight, int calories)
{
	cb.name = name;
	cb.weight = weight;
	cb.calories = calories;
}

void show(const CandyBar& cb)
{
	using std::cout;
	using std::endl;
	cout << "Name: " << cb.name << endl;
	cout << "Weight: " << cb.weight << endl;
	cout << "Calories: " << cb.calories << endl;
}
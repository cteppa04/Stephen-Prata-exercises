#include <iostream>

const int Max = 10;

int main()
{
	using namespace std;

	double score[Max];
	double sum = 0;
	int count = 0;
	int high = 0;
	double avg;
	
	cout << "Enter score:\n";

	int i;
	for (i = 0; i < 10;++i)
	{
		cout << "try #" << i + 1 << ": ";
		if (cin >> score[i])
		{
			++count;
			sum += score[i];
		}
		else
		{
			break;
		}
	}
	avg = sum / count;

	for (i = 0; i < count; i++)
	{
		if (score[i] > avg)
			++high;
	}
	
	cout << "Avg = " << avg << ", elements higher them avg is " << high << endl;

	return 0;
}
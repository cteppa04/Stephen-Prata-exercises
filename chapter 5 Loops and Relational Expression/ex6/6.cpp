#include <iostream>

int main()
{
	using namespace std;

	const int mounths = 12;
	const char* mounth[mounths] =
	{
		"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"
	};
	int books[3][mounths];
	int sum[4] = {};

	cout << "Enter books sallary:\n";

	for (int i = 0; i < 3; ++i)
	{
		cout << i + 1 << " year:\n";
		for (int j = 0; j < mounths; ++j)
		{
			cout << mounth[j] << ": ";
			cin >> books[i][j];
			sum[i] += books[i][j];
			sum[3] += books[i][j];
		}

	}

	cout << "Summary sallary: " << sum[3] << ", first year: " << sum[0] << ", second year: " << sum[1] << ", third year: " << sum[2] << endl;

	return 0;
}
#include <iostream>
#include <cctype>
#include <string>

int main()
{
	using namespace std;

	int vow = 0, cons = 0, other = 0;

	cout << "Enter words (q to quite):\n";
	string word;

	while (cin >> word && word != "q")
	{
		if (isalpha(word[0]))
		{
			switch (word[0])
			{
			case 'A': case 'E': case 'I': case 'J': case 'O': case 'U': case 'Y':
			case 'a': case 'e': case 'i': case 'j': case 'o': case 'u': case 'y':
				++vow;
				break;
			default:
				++cons;
				break;
			}
		}
		else
			++other;
	}

	cout << vow << " words beginning with vowels\n"
		<< cons << " words beginnig with consonants\n"
		<< other << " other";

	return 0;
}
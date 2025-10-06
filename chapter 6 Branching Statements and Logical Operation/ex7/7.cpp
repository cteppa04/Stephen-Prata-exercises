#include <iostream>
#include <cctype>

int main()
{
	using namespace std;

	int vowels = 0, consonants = 0, other = 0;
	char words;

	cout << "Enter words (q to quit):\n";
	cin.get(words);

	while (true)
	{
		if (isalpha(words))
		{
			if (words == 'q')
			{
				cin.get(words);
				if (words == '\n')
					break;
				else
				{
					++consonants;
					while (!isspace(cin.get()))
					{
						continue;
					}
					cin.get(words);
				}
			}
			else
			{
				switch (words)
				{
				case 'A': case 'E': case 'I': case 'J': case 'O': case 'U': case 'Y':
				case 'a': case 'e': case 'i': case 'j': case 'o': case 'u': case 'y':
					++vowels;
					while (!isspace(cin.get()))
					{
						continue;
					}
					cin.get(words);
					break;
				default:
					++consonants;
					while (!isspace(cin.get()))
					{
						continue;
					}
					cin.get(words);
					break;
				}
			}
		}
		else if (isspace(words))
		{
			cin.get(words);
		}
		else
		{
			other++;
			while (!isspace(cin.get()))
			{
				continue;
			}
			cin.get(words);
		}
	}

	cout << vowels << " words beginning with vowels\n"
		<< consonants << " words beginnig with consonants\n"
		<< other << " other";

	return 0;
}
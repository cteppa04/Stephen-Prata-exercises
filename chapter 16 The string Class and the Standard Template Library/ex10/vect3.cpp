#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

struct Review
{
	std::string title;
	int rating;
	double price;
};

bool operator<(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
bool worseThan(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
bool FillReview(std::shared_ptr<Review> rr);
void ShowReview(const std::shared_ptr<Review> rr);
bool priceUp(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);

void Menu();

int main()
{
	srand(time(0));
	using namespace std;;
	char ch;
	vector<shared_ptr<Review>> books;

	shared_ptr<Review> temp;
	while (FillReview(temp))
		books.push_back(std::make_shared<Review>(temp));

	if (books.size() > 0)
	{
		vector<shared_ptr<Review>> titleSort;
		vector<shared_ptr<Review>> ratingSort;
		vector<shared_ptr<Review>> priceSort;
		titleSort = books;
		sort(titleSort.begin(), titleSort.end());
		ratingSort = books;
		sort(ratingSort.begin(), ratingSort.end(), worseThan);
		priceSort = books;
		sort(priceSort.begin(), priceSort.end(), priceUp);

		cout << "Thank you. You entered the following " << books.size() << " ratings and prices:\n";

		Menu();
		while (cin.get(ch) && ch != 'q' && ch != 'Q')
		{
			cin.get();
			switch (ch)
			{
			case 'N':
			case 'n': cout << "Without Sort:\nRating\tPrice\tBook\n";
				for_each(books.begin(), books.end(), ShowReview);
				break;

			case 'T':
			case 't': cout << "Sorted by title:\nRating\tPrice\tBook\n";
				for_each(titleSort.begin(), titleSort.end(), ShowReview);
				break;

			case 'R':
			case 'r': cout << "Sorted by rating:\nRating\tPrice\tBook\n";
				for_each(ratingSort.begin(), ratingSort.end(), ShowReview);
				break;

			case 'U':
			case 'u': cout << "Sorted by price up:\nRating\tPrice\tBool\n";
				for_each(priceSort.begin(), priceSort.end(), ShowReview);
				break;

			case 'D':
			case 'd': cout << "Sorted by price down:\nRating\tPrice\tBool\n";
				for_each(priceSort.rbegin(), priceSort.rend(), ShowReview);
				break;

			default:
				break;
			}
			Menu();
		}
	}
	else
		cout << "No enteries. ";
	cout << "Bye.\n";

	return 0;
}

bool operator<(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2)
{
	if (r1->title < r2->title)
		return true;
	else if (r1->title == r2->title && r1->rating < r2->rating)
		return true;
	else
		return false;
}

bool worseThan(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2)
{
	if (r1->rating < r2->rating)
		return true;
	else
		return false;
}

bool priceUp(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2)
{
	if (r1->price < r2->price)
		return true;
	else
		return false;
}

bool FillReview(std::shared_ptr<Review> rr)
{
	rr = (std::shared_ptr<Review>)new Review;
	std::cout << "Enter bool title (quit to quit): ";
	std::getline(std::cin, rr->title);
	if (rr->title == "quit")
		return false;
	std::cout << "Enter book rating: ";
	std::cin >> rr->rating;
	if (!std::cin)
		return false;
	while (std::cin.get() != '\n')
		continue;
	std::cout << "Enter book price: ";
	std::cin >> rr->price;
	if (!std::cin)
		return false;
	while (std::cin.get() != '\n')
		continue;
	return true;
}

void ShowReview(const std::shared_ptr<Review> rr)
{
	std::cout << rr->rating << "\t" << rr->price << "\t" << rr->title << std::endl;
}

void Menu()
{
	std::cout << "\nHow would you like sort the list:\n";
	std::cout << "n) Without sort\tt) Titel\tr) Rating\n";
	std::cout << "d) Price down\tu) Price up\tq) Quit\n";
	std::cout << "Choise: ";
}

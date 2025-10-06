#include "person.h"
#include <ctime>


//Person
Person::~Person()
{

}

void Person::Show() const
{
	std::cout << "First Name: " << first_name << ",\tSecond Name: " << second_name << std::endl;
}


//Gunslinger
void Gunslinger::Show() const
{
	Person::Show();
	std::cout << "Gunslinger Draw: " << draw << ",\tGunslinger notches: " << notches << std::endl;
}


//Card
const std::string Card::card_rangs[13] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ass"};
const std::string Card::card_suits[4] = { "Clubs", "Diamonds", "Hearts", "Spades" };

Card::Card()
{
	srand(time(0));
	rang = card_rangs[rand() % 13];
	suit = card_suits[rand() % 4];
}

std::ostream& operator<<(std::ostream& os, const Card& card)
{
	os << "Card Rang: " << card.rang << ",\tCard Suit: " << card.suit;
	return os;
}

//PockerPlayer



//BadDude
void BadDude::Show() const
{
	Person::Show();
	std::cout << "BadDude GDraw: " << Gdraw() << std::endl;
	std::cout << "BadDude CDraw: " << Cdraw() << std::endl;
}
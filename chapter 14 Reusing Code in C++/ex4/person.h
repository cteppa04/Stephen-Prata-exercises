#ifndef PERSON_H_
#define PERSON_H_
#include <iostream>
#include <string>

class Person
{
private:
	std::string first_name;
	std::string second_name;
public:
	Person(std::string s1 = "none", std::string s2 = "none") : first_name(s1), second_name(s2) {};
	virtual ~Person() = 0;
	virtual void Show() const;
};

class Gunslinger : virtual public Person
{
private:
	double draw;
	int notches;
public:
	Gunslinger() : Person(), draw(0), notches(0) {};
	Gunslinger(std::string s1, std::string s2, double d = 0, int n = 0) : Person(s1, s2), draw(d), notches(n) {};
	~Gunslinger() {};
	double Draw() const { return draw; };
	void Show() const override;
};

class Card
{
private:
	const static std::string card_rangs[13];
	const static std::string card_suits[4];
	std::string rang;
	std::string suit;
public:
	Card();
	~Card() {};
	friend std::ostream& operator<<(std::ostream& os, const Card& card);
};

class PockerPlayer : virtual public Person
{
private:
	Card card;
public:
	PockerPlayer(std::string s1 = "none", std::string s2 = "none") : Person(s1, s2), card() {};
	~PockerPlayer() {};
	Card Draw() const { return card; };
};

class BadDude : public Gunslinger, public PockerPlayer
{
private:

public:
	BadDude(std::string s1 = "none", std::string s2 = "none", double d = 0, int n = 0) : Person(s1, s2), Gunslinger(s1, s2, d, n), PockerPlayer(s1, s2) {};
	double Gdraw() const { return Gunslinger::Draw(); };
	Card Cdraw() const { return PockerPlayer::Draw(); };
	void Show() const override;
};

#endif // !PERSON_H_

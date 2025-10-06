#ifndef HEADER_H_
#define HEADER_H_

#include <valarray>
#include <iostream>
#include <string>

template <class T1, class T2>
class Pair
{
private:
	T1 a;
	T2 b;
public:
	int sum() const { return b.sum(); };
	T1& first();
	T2& second();
	T1 first() const { return a; }
	T2 second() const { return b; }
	Pair(const T1& aval, const T2& bval) : a(aval), b(bval) {}
	Pair() {};
};

template<class T1, class T2>
T1& Pair<T1, T2>::first()
{
	return a;
}
template<class T1, class T2>
T2& Pair<T1, T2>::second()
{
	return b;
}

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine : private std::string, private PairArray
{
private:
	int years;
public:
	Wine(const char* l, int y, const int yr[], const int bot[]);
	Wine(const char* l, int y) : std::string(l), years(y), PairArray(ArrayInt(y), ArrayInt(y)) {};
	std::string Label() const { return (const std::string&)*this; };
	using PairArray::sum;
	void GetBottles();
	void Show() const;
};

#endif // !HEADER_H_
#pragma once
#ifndef COMPLEX0_H_
#define COMPLEX0_H_
#include <iostream>

class complex
{
private:
	int real;
	int img;
public:
	complex();
	complex(int r, int ig);
	~complex() {}
	complex operator~() const;
	complex operator+(const complex& c) const;
	complex operator-(const complex& c) const;
	complex operator*(const complex& c) const;
	complex operator*(double v) const;
	friend complex operator*(double v, const complex& c);
	friend std::istream& operator>>(std::istream& ci, complex& c);
	friend std::ostream& operator<<(std::ostream& co, const complex& c);
};

#endif // !COMPLEX0_H_

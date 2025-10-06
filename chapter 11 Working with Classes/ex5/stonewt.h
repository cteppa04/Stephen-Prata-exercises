#pragma once
#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>

class Stonewt
{
public:
	enum Mode { Sto = 1, IPds = 2, Pds = 3 };
private:
	enum { Lbs_per_stn = 14 };
	Mode mode;
	int stone;
	double pds_left;
	double pounds;
public:
	Stonewt(double lbs);
	Stonewt(int stn, double lbs, Mode m = Sto);
	Stonewt();
	~Stonewt();
	void setSto() { mode = Sto; }
	void setIPds() { mode = IPds; }
	void setPds() { mode = Pds; }
	Stonewt operator+(const Stonewt& st) const;
	Stonewt operator-(const Stonewt& st) const;
	Stonewt operator*(double mult) const;
	friend Stonewt operator*(double mult, const Stonewt& st) { return st * mult; }
	friend std::ostream& operator<<(std::ostream& co, const Stonewt& st);
};

#endif // !STONEWT_H_

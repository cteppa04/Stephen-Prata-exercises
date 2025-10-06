#pragma once
#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt
{
private:
	enum { Lbs_per_stn = 14 };
	int stone;
	double pds_left;
	double pounds;
public:
	Stonewt(double lbs);
	Stonewt(int stn, double lbs);
	Stonewt();
	~Stonewt();
	void show_lbs() const;
	void show_stn() const;
	friend bool operator<(const Stonewt& st1, const Stonewt& st2);
	friend bool operator>(const Stonewt& st1, const Stonewt& st2);
	friend bool operator==(const Stonewt& st1, const Stonewt& st2);
	friend bool operator!=(const Stonewt& st1, const Stonewt& st2);
	friend bool operator<=(const Stonewt& st1, const Stonewt& st2);
	friend bool operator>=(const Stonewt& st1, const Stonewt& st2);
};

#endif // !STONEWT_H_

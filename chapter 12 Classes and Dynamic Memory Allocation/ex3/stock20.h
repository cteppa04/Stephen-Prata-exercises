#pragma once
#ifndef STOCK20_H_
#define STOCK20_H_
#include <iostream>

class Stock
{
private:
	char* company;
	long shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = share_val * shares; }
public:
	Stock();
	Stock(const char* co, long n = 0, double pr = 0);
	~Stock();
	void bye(long num, double price);
	void sell(long num, double price);
	void update(double price);
	const Stock& topval(const Stock& s) const;
	friend std::ostream& operator<<(std::ostream& os, const Stock& st);
	Stock(const Stock& st);
	Stock& operator=(const Stock& st);
};

#endif // !STOK+C
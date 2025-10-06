#pragma once
#ifndef BANK_H_
#define BANK_H_
#include <string>

class Bank
{
private:
	std::string name;
	std::string number;
	double balans;
public:
	Bank(const std::string acc_name, const std::string acc_number, double acc_balans = 0.0);
	void show() const;
	void donate(double value);
	void get(double value);
};

#endif // !BANK_H_

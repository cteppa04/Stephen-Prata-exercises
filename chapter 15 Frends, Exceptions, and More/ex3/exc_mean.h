#include <iostream>
#include <stdexcept>
#include <string>

class base_e : public std::logic_error
{
private:
	double v1;
	double v2;
protected:
	double Val1() const { return v1; }
	double Val2() const { return v2; }
public:
	base_e(double a, double b) : std::logic_error(""), v1(a), v2(b) {}
	virtual std::string Name() const { return "base_e"; }
	void show() const { std::cout << "Error in class " << Name() << ", wrong values: " << Val1() << ", " << Val2() << std::endl; }
};

class bad_hmean : public base_e
{
private:

public:
	bad_hmean(double a = 0, double b = 0) : base_e(a, b) {}
	std::string Name() const { return "bad_hmean"; }
};

class bad_gmean : public base_e
{
public:
	bad_gmean(double a = 0, double b = 0) : base_e(a, b) {}
	std::string Name() const { return "bad_gmean"; }
};

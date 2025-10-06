#include <iostream>
#include <stdexcept>

class bad_hmean : public std::logic_error
{
public:
	bad_hmean() : logic_error("In bad_hmean object a can't be equal to -b.\n") {}
};

class bad_gmean : public std::logic_error
{
public:
	bad_gmean() : logic_error("") {}
	const char* what() const { return "In bad_gmean object a and b can't be negative.\n"; }
};
#include "emp.h"


//abstr_emp
abstr_emp::abstr_emp() : fname("none"), lname("none"), job("none") {}

abstr_emp::abstr_emp(const std::string& fn, const std::string& ln, const std::string& j) : fname(fn), lname(ln), job(j) {}

void abstr_emp::ShowAll() const
{
	std::cout << "Name: " << fname << " " << lname << std::endl;
	std::cout << "Job: " << job << std::endl;
}

void abstr_emp::SetAll()
{
	std::cout << "Enter first name: ";
	std::getline(std::cin, fname);
	std::cout << "Enter last name: ";
	std::getline(std::cin, lname);
	std::cout << "Enter a job: ";
	std::getline(std::cin, job);
}

std::ostream& operator<<(std::ostream& os, const abstr_emp& e)
{
	os << "Name: " << e.fname << " " << e.lname << std::endl;
	return os;
}

abstr_emp::~abstr_emp() {}


//employee
employee::employee() : abstr_emp() {}

employee::employee(const std::string& fn, const std::string& ln, const std::string& j) : abstr_emp(fn, ln, j) {}

void employee::ShowAll() const { abstr_emp::ShowAll(); }

void employee::SetAll() { abstr_emp::SetAll(); }


//manager
manager::manager() : abstr_emp(), inchargeof(0) {}

manager::manager(const std::string& fn, const std::string& ln, const std::string& j, int ico) : abstr_emp(fn, ln, j), inchargeof(ico) {}

manager::manager(const abstr_emp& e, int ico) : abstr_emp(e), inchargeof(ico) {}

manager::manager(const manager& m) : abstr_emp(m), inchargeof(m.inchargeof) {}

void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	std::cout << "In charge of: " << inchargeof << std::endl;
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	std::cout << "Enter in charge of: ";
	std::cin >> inchargeof;
}


//fink
fink::fink() : abstr_emp(), reportsto("none") {}

fink::fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo) : abstr_emp(fn, ln, j), reportsto(rpo) {}

fink::fink(const abstr_emp& e, const std::string& rpo) : abstr_emp(e), reportsto(rpo) {}

fink::fink(const fink& f) : abstr_emp(f), reportsto(f.reportsto) {}

void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	std::cout << "Reports to: " << reportsto << std::endl;
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	std::cout << "Enter reports to: ";
	std::getline(std::cin, reportsto);
}


//highfink
highfink::highfink() : abstr_emp(), manager(), fink() {}

highfink::highfink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo, int ico) : abstr_emp(fn, ln, j), 
	manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {}

highfink::highfink(const abstr_emp& e, const std::string& rpo, int ico) : abstr_emp(e), manager(e, ico), fink(e, rpo) {}

highfink::highfink(const fink& f, int ico) : abstr_emp(f), fink(f), manager(f, ico) {}

highfink::highfink(const manager& m, const std::string& rpo) : abstr_emp(m), manager(m), fink(m, rpo) {}

highfink::highfink(const highfink& h) : abstr_emp(h), manager(h), fink(h) {}

void highfink::ShowAll() const
{
	abstr_emp::ShowAll();
	std::cout << "In charge of: " << manager::InChargeOf() << std::endl;
	std::cout << "Reports to: " << fink::ReportsTo() << std::endl;
}

void highfink::SetAll()
{
	abstr_emp::SetAll();
	std::cout << "Enter in charge of: ";
	std::cin >> InChargeOf();
	std::cin.get();
	std::cout << "Enter reports to: ";
	std::getline(std::cin, fink::ReportsTo());
}
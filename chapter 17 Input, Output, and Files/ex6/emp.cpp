#include "emp.h"


//employee
employee::employee() : fname("none"), lname("none"), job("none") {}

employee::employee(const std::string& fn, const std::string& ln, const std::string& j) : fname(fn), lname(ln), job(j) {}

void employee::ShowAll() const
{
	std::cout << "Name: " << fname << " " << lname << std::endl;
	std::cout << "Job: " << job << std::endl;
}

void employee::SetAll()
{
	std::cout << "Enter first name: ";
	std::getline(std::cin, fname);
	std::cout << "Enter last name: ";
	std::getline(std::cin, lname);
	std::cout << "Enter a job: ";
	std::getline(std::cin, job);
}

std::ostream& operator<<(std::ostream& os, const employee& e)
{
	os << "Name: " << e.fname << " " << e.lname << std::endl;
	return os;
}

void employee::writeAll(std::ostream& os) const
{
	os << Employee << std::endl << fname << std::endl << lname << std::endl << job << std::endl;
}

void employee::getAll(std::istream& is)
{
	getline(is, fname);
	getline(is, lname);
	getline(is, job);
}



//manager
manager::manager() : employee(), inchargeof(0) {}

manager::manager(const std::string& fn, const std::string& ln, const std::string& j, int ico) : employee(fn, ln, j), inchargeof(ico) {}

manager::manager(const employee& e, int ico) : employee(e), inchargeof(ico) {}

manager::manager(const manager& m) : employee(m), inchargeof(m.inchargeof) {}

void manager::ShowAll() const
{
	employee::ShowAll();
	std::cout << "In charge of: " << inchargeof << std::endl;
}

void manager::SetAll()
{
	employee::SetAll();
	std::cout << "Enter in charge of: ";
	std::cin >> inchargeof;
}

void manager::writeAll(std::ostream& os) const
{
	os << Manager << std::endl << employee::Fname() << std::endl << employee::Lname() << std::endl << employee::Job() << std::endl << inchargeof << std::endl;
}

void manager::getAll(std::istream& is)
{
	employee::getAll(is);
	is >> inchargeof;
	is.get();
}



//fink
fink::fink() : employee(), reportsto("none") {}

fink::fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo) : employee(fn, ln, j), reportsto(rpo) {}

fink::fink(const employee& e, const std::string& rpo) : employee(e), reportsto(rpo) {}

fink::fink(const fink& f) : employee(f), reportsto(f.reportsto) {}

void fink::ShowAll() const
{
	employee::ShowAll();
	std::cout << "Reports to: " << reportsto << std::endl;
}

void fink::SetAll()
{
	employee::SetAll();
	std::cout << "Enter reports to: ";
	std::getline(std::cin, reportsto);
}

void fink::writeAll(std::ostream& os) const
{
	os << Fink << std::endl << employee::Fname() << std::endl << employee::Lname() << std::endl << employee::Job() << std::endl << reportsto << std::endl;
}

void fink::getAll(std::istream& is)
{
	employee::getAll(is);
	getline(is, reportsto);
}



//highfink
highfink::highfink() : employee(), manager(), fink() {}

highfink::highfink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo, int ico) : employee(fn, ln, j),
manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {
}

highfink::highfink(const employee& e, const std::string& rpo, int ico) : employee(e), manager(e, ico), fink(e, rpo) {}

highfink::highfink(const fink& f, int ico) : employee(f), fink(f), manager(f, ico) {}

highfink::highfink(const manager& m, const std::string& rpo) : employee(m), manager(m), fink(m, rpo) {}

highfink::highfink(const highfink& h) : employee(h), manager(h), fink(h) {}

void highfink::ShowAll() const
{
	employee::ShowAll();
	std::cout << "In charge of: " << manager::InChargeOf() << std::endl;
	std::cout << "Reports to: " << fink::ReportsTo() << std::endl;
}

void highfink::SetAll()
{
	employee::SetAll();
	std::cout << "Enter in charge of: ";
	std::cin >> InChargeOf();
	std::cin.get();
	std::cout << "Enter reports to: ";
	std::getline(std::cin, fink::ReportsTo());
}

void highfink::writeAll(std::ostream& os) const
{
	os << Highfink << std::endl << employee::Fname() << std::endl << employee::Lname() << std::endl << employee::Job() << std::endl << manager::InChargeOf() << std::endl << fink::ReportsTo() << std::endl;
}

void highfink::getAll(std::istream& is)
{
	employee::getAll(is);
	is >> InChargeOf();
	is.get();
	getline(is, fink::ReportsTo());
}
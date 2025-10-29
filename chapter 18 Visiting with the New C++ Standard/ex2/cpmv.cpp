#include "cpmv.h"

Cpmv::Cpmv()
{
	std::cout << "\nDefault constructor:\n";
	pi = new Info;
	pi->qcode = "none";
	pi->zcode = "none";
}

Cpmv::Cpmv(std::string q, std::string z)
{
	std::cout << "\nConstructor with strings:\n";
	pi = new Info({ q, z });
}

Cpmv::Cpmv(const Cpmv& cp) 
{
	std::cout << "\nCopy constructor:\n";
	pi = new Info;
	*pi = *(cp.pi);
}

Cpmv::Cpmv(Cpmv&& mv)
{
	std::cout << "\nMove constructor:\n";
	pi = mv.pi;
	mv.pi = nullptr;
}

Cpmv::~Cpmv()
{
	delete pi;
}

Cpmv& Cpmv::operator=(const Cpmv& cp)
{
	std::cout << "\nAssign:\n";
	if (this == &cp)
		return *this;
	delete pi;
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	return *this;
}

Cpmv& Cpmv::operator=(Cpmv&& mv)
{
	std::cout << "\nAssign with move:\n";
	if (this != &mv)
	{
		delete pi;
		pi = mv.pi;
		mv.pi = nullptr;
	}
	return *this;
}

Cpmv Cpmv::operator+(const Cpmv& obj) const
{
	std::cout << "\nSum operator:\n";
	std::string sum1, sum2;
	sum1 = pi->qcode + obj.pi->qcode;
	sum2 = pi->zcode + obj.pi->zcode;
	return Cpmv(sum1, sum2);
}

void Cpmv::Display() const
{
	std::cout << "First info: " << pi->qcode << std::endl;
	std::cout << "Second info: " << pi->zcode << std::endl;
}
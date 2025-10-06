#include "complex0.h"

complex::complex()
{
	real = img = 0;
}

complex::complex(int r, int ig)
{
	real = r;
	img = ig;
}

complex complex::operator~() const
{
	return complex(real, -img);
}

complex complex::operator+(const complex& c) const
{
	return complex(real + c.real, img + c.img);
}

complex complex::operator-(const complex& c) const
{
	return complex(real - c.real, img - c.img);
}

complex complex::operator*(const complex& c) const
{
	return complex(real * c.real - img * c.img, real * c.img + c.real * img);
}

complex complex::operator*(double v) const
{
	return complex(v * real, v * img);
}

complex operator*(double v, const complex& c)
{
	return complex(v * c.real, v * c.img);
}

std::istream& operator>>(std::istream& ci, complex& c)
{
	std::cout << "real: ";
	if (ci >> c.real)
	{
		std::cout << "imaginary: ";
		ci >> c.img;
	}
	return ci;
}

std::ostream& operator<<(std::ostream& co, const complex& c)
{
	co << "(" << c.real << "," << c.img << "i)";
	return co;
}
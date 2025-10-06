#include "dma.h"
#include <cstring>

//
ABC::ABC(const char* l, int r)
{
	label = new char[strlen(l) + 1];
	strcpy_s(label, strlen(l) + 1, l);
	rating = r;
}

ABC::~ABC()
{
	delete[] label;
}

ABC& ABC::operator=(const ABC& rs)
{
	if (this == &rs)
		return *this;
	delete[] label;
	label = new char[strlen(rs.label) + 1];
	strcpy_s(label, strlen(rs.label) + 1, rs.label);
	rating = rs.rating;
	return *this;
}

void ABC::View() const
{
	std::cout << "Label: " << label << std::endl;
	std::cout << "Rating: " << rating << std::endl;
}

std::ostream& operator<<(std::ostream& os, const ABC& rs)
{
	os << "Label: " << rs.label << std::endl;
	os << "Rating: " << rs.rating << std::endl;
	return os;
}


//
std::ostream& operator<<(std::ostream& os, const baseDMA& rs)
{
	os << (const ABC&)rs;
	return os;
}

void baseDMA::View() const
{
	ABC::View();
}

baseDMA& baseDMA::operator=(const baseDMA& rs)
{
	ABC::operator=(rs);
	return *this;
}


//
lacksDMA::lacksDMA(const char* c, const char* l, int r) : ABC(l, r)
{
	strcpy_s(color, 40, c);
	color[39] = '\0';
}

lacksDMA::lacksDMA(const char* c, const ABC& rs) : ABC(rs)
{
	strcpy_s(color, COL_LEN, c);
	color[COL_LEN - 1] = '\0';
}

std::ostream& operator<<(std::ostream& os, const lacksDMA& ls)
{
	os << (const ABC&)ls;
	os << "Color: " << ls.color << std::endl;
	return os;
}

void lacksDMA::View() const
{
	ABC::View();
	std::cout << "Color: " << color << std::endl;
}


//
hasDMA::hasDMA(const char* s, const char* l, int r) : ABC(l, r)
{
	style = new char[strlen(s) + 1];
	strcpy_s(style, strlen(s) + 1, s);
}

hasDMA::hasDMA(const char* s, const ABC& rs) : ABC(rs)
{
	style = new char[strlen(s) + 1];
	strcpy_s(style, strlen(s) + 1, s);
}

hasDMA::hasDMA(const hasDMA& hs) : ABC(hs)
{
	style = new char[strlen(hs.style) + 1];
	strcpy_s(style, strlen(hs.style) + 1, hs.style);
}

hasDMA::~hasDMA()
{
	delete[] style;
}

hasDMA& hasDMA::operator=(const hasDMA& hs)
{
	if (this == &hs)
		return *this;
	ABC::operator=(hs);
	delete[] style;
	style = new char[strlen(hs.style) + 1];
	strcpy_s(style, strlen(hs.style) + 1, hs.style);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const hasDMA& hs)
{
	os << (const ABC&)hs;
	os << "Style: " << hs.style << std::endl;
	return os;
}

void hasDMA::View() const
{
	ABC::View();
	std::cout << "Style: " << style << std::endl;
}
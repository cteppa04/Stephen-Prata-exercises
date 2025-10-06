#include "vintageport.h"

VintagePort::VintagePort() : Port("The Noble", "Vintage", 0)
{
	nickname = new char[5];
	strcpy_s(nickname, 5, "none");
	year = 1900;
}

VintagePort::VintagePort(const char* br, int b, const char* nn, int y) : Port(br, "Vintage", b)
{
	nickname = new char[strlen(nn) + 1];
	strcpy_s(nickname, strlen(nn) + 1, nn);
	year = y;
}

VintagePort::VintagePort(const VintagePort& vp) : Port(vp)
{
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy_s(nickname, strlen(vp.nickname) + 1, vp.nickname);
	year = vp.year;
}

VintagePort& VintagePort::operator=(const VintagePort& vp)
{
	Port::operator=(vp);
	delete[] nickname;
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy_s(nickname, strlen(vp.nickname) + 1, vp.nickname);
	year = vp.year;
	return *this;
}

void VintagePort::Show() const
{
	Port::Show();
	cout << "Nickname: " << nickname << endl;
	cout << "Year: " << year << endl;
}

ostream& operator<<(ostream& os, const VintagePort& vp)
{
	os << (Port&)vp << ", " << vp.nickname << ", " << vp.year;
	return os;
}
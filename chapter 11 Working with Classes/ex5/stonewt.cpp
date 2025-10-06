#include <iostream>
using std::cout;
#include "stonewt.h"

Stonewt::Stonewt(double lbs)
{
	mode = Sto;
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn;
	pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs, Mode m)
{
	mode = m;
	if (mode == Sto || mode == IPds || mode == Pds)
	{
		stone = stn;
		pds_left = lbs;
		pounds = stn * Lbs_per_stn + lbs;
	}
	else
	{
		mode = Sto;
		pounds = stone = pds_left = 0;
	}
}

Stonewt::Stonewt()
{
	mode = Sto;
	pounds = stone = pds_left = 0;
}

Stonewt::~Stonewt()
{

}

Stonewt Stonewt::operator+(const Stonewt& st) const
{
	return Stonewt(pounds + st.pounds);
}

Stonewt Stonewt::operator-(const Stonewt& st) const
{
	return Stonewt(pounds - st.pounds);
}

Stonewt Stonewt::operator*(double mult) const
{
	return Stonewt(pounds * mult);
}

std::ostream& operator<<(std::ostream& co, const Stonewt& st) 
{
	switch (st.mode)
	{
	case Stonewt::Pds: co << st.pounds << " pounds\n";
		break;
	case Stonewt::IPds: co << int(st.pounds) << " pounds\n";
		break;
	case Stonewt::Sto: co << st.stone << " stone, " << st.pds_left << " pounds\n";
		break;
	default:
		break;
	}
	return co;
}
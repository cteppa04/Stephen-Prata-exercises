#ifndef CLASSIC_H_
#define CLASSIC_H_

#include "cd.h"	

class Classic : public Cd
{
private:
	enum { LEN = 40 };
	char primary_work[LEN];
public:
	Classic(const char* s0, const char* s1, const char* s2, int n, double x);
	Classic(const Classic& d);
	Classic();
	~Classic();
	virtual void Report() const;
	Classic& operator=(const Classic& d);
};

#endif // !CLASSIC_H_

#pragma once
#ifndef PROLOG_H_
#define PROLOG_H_

class Plorga
{
private:
	static const int SIZE = 20;
	char name[SIZE];
	int ci;
public:
	Plorga(const char* pname = "Plorga", int pci = 50);
	void change_ci(int pci);
	void show();
};

#endif // !PROLOG_H_

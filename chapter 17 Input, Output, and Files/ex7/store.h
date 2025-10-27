#ifndef STORE_H
#include <iostream>
#include <fstream>
#include <string>

class Store
{
private:
	std::ofstream& oustput;
public:
	Store(std::ofstream& os);
	void operator()(const std::string& str);
};

#endif // !STORE_H

#include "store.h"

Store::Store(std::ofstream& os) : output(os)
{

}

void Store::operator()(const std::string& str)
{
	int len = str.size();
	output.write((char*)&len, sizeof(std::size_t));
	output.write(str.data(), len);
}
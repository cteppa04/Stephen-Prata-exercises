#include <iostream>

struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void output(box str);
void change_vol(box* str);

int main()
{
	box b1 = { "Giga mor", 2.0, 1.0, 1.0, 2 };
	box b2 = { "chipi chipe", 3,3,3,0 };

	output(b1);
	change_vol(&b2);
	output(b2);

	return 0;
}

void output(box str)
{
	using namespace std;
	cout << "Maker: " << str.maker << ", height: " << str.height << ", width: " << str.width << ", length: " << str.length
		<< ", volume: " << str.volume << endl;
}

void change_vol(box* str)
{
	str->volume = str->height * str->length * str->width;
}
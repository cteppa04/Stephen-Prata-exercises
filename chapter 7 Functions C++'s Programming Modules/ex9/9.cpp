#include <iostream>
using namespace std;

const int SLEN = 30;
struct student
{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(const student* st);
void display3(const student pa[], int n);

int main()
{
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n')
		continue;
	student* ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete[] ptr_stu;
	cout << "\nDone\n";
	return 0;
}

int getinfo(student pa[], int n)
{
	cout << "\nEnter an information:\n";
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "Student #" << i + 1 << endl;
		cout << "Name(enter to quit): ";
		if (cin.getline(pa[i].fullname, SLEN) && pa[i].fullname[0] != '\0')
		{
			cout << "Hobby: ";
			cin.getline(pa[i].hobby, SLEN);
			cout << "Ooplevel: ";
			(cin >> pa[i].ooplevel).get();
		}
		else
		{
			break;
		}
	}
	return i;
}

void display1(student st)
{
	cout << "\nStudent info(d1) :\n";
	cout << "Name: " << st.fullname << ", hobby: " << st.hobby << ", ooplevel: " << st.ooplevel << endl;
}

void display2(const student* st)
{
	cout << "Student info(d2):\n";
	cout << "Name: " << st->fullname << ", hobby: " << (*st).hobby << ", ooplevel: " << st->ooplevel << endl;
}

void display3(const student pa[], int n)
{
	cout << "\nAll students info:\n";
	for (int i = 0; i < n; i++)
	{
		cout << "Student #" << i + 1 << ":\n";
		cout << "Name: " << pa[i].fullname << ", hobby: " << pa[i].fullname << ", ooplevel: " << pa[i].ooplevel << endl;
	}
}
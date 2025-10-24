#ifndef EMP_H_
#define EMP_H_

#include <iostream>
#include <string>

enum classkind { Employee = 1, Manager = 2, Fink = 3, Highfink = 4 };

class employee
{
private:
	std::string fname;
	std::string lname;
	std::string job;
public:
	employee();
	employee(const std::string& fn, const std::string& ln, const std::string& j);
	virtual void ShowAll() const;
	virtual void SetAll();
	friend std::ostream& operator<<(std::ostream& os, const employee& e);
	virtual ~employee() {};
	virtual void writeAll(std::ostream& os) const;
	virtual void getAll(std::istream& is);
protected:
	const std::string Fname() const { return fname; };
	const std::string Lname() const { return lname; };
	const std::string Job() const { return job; };
};

class manager : virtual public employee
{
private:
	int inchargeof;
protected:
	int InChargeOf() const { return inchargeof; };
	int& InChargeOf() { return inchargeof; };
public:
	manager();
	manager(const std::string& fn, const std::string& ln, const std::string& j, int ico = 0);
	manager(const employee& e, int ico);
	manager(const manager& m);
	virtual void ShowAll() const override;
	virtual void SetAll();
	virtual void writeAll(std::ostream& os) const;
	virtual void getAll(std::istream& is);
};

class fink : virtual public employee
{
private:
	std::string reportsto;
protected:
	const std::string ReportsTo() const { return reportsto; };
	std::string& ReportsTo() { return reportsto; };
public:
	fink();
	fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo);
	fink(const employee& e, const std::string& rpo);
	fink(const fink& f);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void writeAll(std::ostream& os) const;
	virtual void getAll(std::istream& is);
};

class highfink : public manager, public fink
{
public:
	highfink();
	highfink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo, int ico);
	highfink(const employee& e, const std::string& rpo, int ico);
	highfink(const fink& f, int ico);
	highfink(const manager& m, const std::string& rpo);;
	highfink(const highfink& h);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void writeAll(std::ostream& os) const;
	virtual void getAll(std::istream& is);
};

#endif // !EMP_H_

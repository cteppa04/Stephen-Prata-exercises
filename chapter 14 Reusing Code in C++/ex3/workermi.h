#ifndef WORKERMI_H_
#define WORKERMI_H_
#include <string>

class Worker
{
private:
	std::string fullname;
	long id;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Worker() : fullname("no one"), id(0L) {};
	Worker(const std::string& s, long n) : fullname(s), id(n) {};
	virtual ~Worker() = 0;
	virtual void Set() = 0;
	virtual void Show() const = 0;
};

class Waiter : virtual public Worker
{
private:
	int panache;
protected:
	void Data() const;
	void Get();
public:
	Waiter() : Worker(), panache(0) {};
	Waiter(const std::string& s, long n, int p = 0) : Worker(s, n), panache(p) {};
	Waiter(const Worker& wk, int p = 0) : Worker(wk), panache(p) {};
	void Set();
	void Show() const;
};

class Singer : virtual public Worker
{
protected:
	enum { other, alto, contralto, soprano, bass, baritone, tenor };
	enum { Vtypes = 7 };
	void Data() const;
	void Get();
private:
	static const char* pv[Vtypes];
	int voice;
public:
	Singer() : Worker(), voice(other) {};
	Singer(const std::string& s, long n, int v = other) : Worker(s, n), voice(v) {};
	Singer(const Worker& wk, int v = other) : Worker(wk), voice(v) {};
	void Set();
	void Show() const;
};

class SingingWaiter : public Singer, public Waiter
{
protected:
	void Data() const;
	void Get();
public:
	SingingWaiter() {};
	SingingWaiter(const std::string& s, long n, int p = 0, int v = other) : Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {};
	SingingWaiter(const Worker& wk, int p = 0, int v = other) : Worker(wk), Waiter(wk, p), Singer(wk, v) {};
	void Set();
	void Show() const;
};

template <typename Item>
class QueueTp
{
private:
	struct Node { Item item; struct Node* next; };
	enum { Q_SIZE = 10 };
	Node* front;
	Node* rear;
	int items;
	const int qsize;
	QueueTp(const QueueTp& q) : qsize(0) {}
	QueueTp& operator=(const QueueTp& q) { return *this; }
public:
	QueueTp(int qs = Q_SIZE);
	~QueueTp();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item& item);
	bool dequeue(Item& item);
};

template <typename Item>
QueueTp<Item>::QueueTp(int qs) : qsize(qs)
{
	front = rear = 0;
	items = 0;
}

template <typename Item>
QueueTp<Item>::~QueueTp()
{
	Node* temp;
	while (front != 0)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

template <typename Item>
bool QueueTp<Item>::isempty() const
{
	return items == 0;
}

template <typename Item>
bool QueueTp<Item>::isfull() const
{
	return items == qsize;
}

template <typename Item>
int QueueTp<Item>::queuecount() const
{
	return items;
}

template <typename Item>
bool QueueTp<Item>::enqueue(const Item& item)
{
	if (isfull())
		return false;
	Node* add = new Node;
	add->item = item;
	add->next = nullptr;
	items++;
	if (front == nullptr)
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}

template <typename Item>
bool QueueTp<Item>::dequeue(Item& item)
{
	if (front == nullptr)
		return false;
	item = front->item;
	items--;
	Node* temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
		rear = nullptr;
	return true;
}

#endif // !WORKERMI_H_

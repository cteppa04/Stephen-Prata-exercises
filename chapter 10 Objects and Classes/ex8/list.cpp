#include <iostream>
#include "list.h"

List::List()
{
	top = 0;
}

bool List::isempty() const
{
	return top == 0;
}

bool List::isfull() const
{
	return top == MAX;
}

bool List::push(const Item& item)
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}

void List::visit(void (*pf)(Item&))
{
	for (int i = 0; i < top; i++)
	{
		(*pf)(items[i]);
	}
}

void change(Item& it)
{
	std::cout << "Enter new value: ";
	std::cin >> it;
}

void sqr(Item& it)
{
	it *= it;
}

void List::show() const
{
	if (isempty())
		std::cout << "stack is empty";
	else
		for (int i = 0; i < top; i++)
		{
			std::cout << i + 1 << " element: " << items[i] << std::endl;
		}
}
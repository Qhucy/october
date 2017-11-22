#pragma once
#include "item.h"

class inventory
{
	public:
		inventory();
		inventory(int size, std::vector<item>);
		int getSize();
		std::vector<item> getContents();
		bool containsItem(item);
		void setSize(int);
		void addSize(int);
		void subtractSize(int);
		void setContents(std::vector<item>);
		void addItem(item);
		void removeItem(item);
	private:
		int size;
		std::vector<item> items;
};

inventory::inventory()
{

}

inventory::inventory(int a, std::vector<item> b)
{
	size = a;
	items = b;
}

int inventory::getSize()
{
	return size;
}

std::vector<item> inventory::getContents()
{
	return items;
}

bool inventory::containsItem(item q)
{
	if (items.empty()) return false;
	if (std::find(items.begin(), items.end(), q) != items.end()) return true;
	else return false;
	return false;
}

void inventory::setSize(int q)
{
	size = q;
}

void inventory::addSize(int q)
{
	size += q;
}

void inventory::subtractSize(int q)
{
	if ((size - q) < 1) size = 1;
	else size -= q;
}

void inventory::setContents(std::vector<item> q)
{
	items = q;
}

void inventory::addItem(item q)
{
	items.push_back(q);
}

void inventory::removeItem(item q)
{
	std::vector<item> contents;
	for (int i = 0; i < items.size(); i++)
	{
		if (q.equals(contents.at(i))) continue;
		else contents.push_back(contents.at(i));
	}
	items = contents;
}
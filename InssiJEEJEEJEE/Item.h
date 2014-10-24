#pragma once
#include <string>

class Item
{
private:
	unsigned int price;
	std::string name;

public:
	Item(char *name, unsigned int price);
	~Item();

	inline unsigned int getPrice() { return price; }
	inline const std::string& getName() { return name; }

	virtual void use() = 0;
};
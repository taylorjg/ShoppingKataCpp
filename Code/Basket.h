#ifndef SHOPPINGKATACODE_BASKET_H
#define SHOPPINGKATACODE_BASKET_H

#include <vector>
#include <string>
#include <functional>

namespace ShoppingKataCode {

class Basket
{
public:
	void Add(const std::string& item);
	void ForEachItem(std::function<void (const std::string&)> action) const;

private:
	std::vector<std::string> _items;
};

}

#endif

#include "stdafx.h"
#include "Basket.h"

#include <algorithm>

namespace ShoppingKataCode {

void Basket::Add(const std::string& item)
{
	_items.push_back(item);
}

void Basket::ForEachItem(std::function<void (const std::string&)> action) const
{
	std::for_each(_items.begin(), _items.end(), action);
}

}

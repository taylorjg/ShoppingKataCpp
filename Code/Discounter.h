#ifndef SHOPPINGKATACODE_DISCOUNTER_H
#define SHOPPINGKATACODE_DISCOUNTER_H

#include <vector>
#include <string>

namespace ShoppingKataCode {

class DiscountRule;

class Discounter
{
public:
	Discounter();
	int Discount(const std::string& item);

private:
	std::vector<DiscountRule*> _discountRules;
};

}

#endif

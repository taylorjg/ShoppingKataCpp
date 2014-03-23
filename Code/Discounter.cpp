#include "stdafx.h"
#include "Discounter.h"

#include <numeric>

namespace ShoppingKataCode {

Discounter::Discounter()
	// : _discountRules({
	// 	DiscountRule("A", 3, 20),
	// 	DiscountRule("B", 2, 15)
	// })
{
	_discountRules.push_back(DiscountRule("A", 3, 20));
	_discountRules.push_back(DiscountRule("B", 2, 15));
}

int Discounter::Discount(const std::string& item)
{
	return std::accumulate(_discountRules.begin(), _discountRules.end(), 0, [item](int acc, DiscountRule& rule){
		return acc + rule.GetApplicableDiscount(item);
	});
}

}

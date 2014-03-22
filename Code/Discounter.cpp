#include "stdafx.h"
#include "Discounter.h"
#include "DiscountRule.h"

#include <numeric>

namespace ShoppingKataCode {

Discounter::Discounter()
{
	_discountRules.push_back(new DiscountRule("A", 3, 20));
	_discountRules.push_back(new DiscountRule("B", 2, 15));
}

int Discounter::Discount(const std::string& item)
{
	return std::accumulate(_discountRules.begin(), _discountRules.end(), 0, [item](int acc, DiscountRule* rule){
		return acc + rule->GetApplicableDiscount(item);
	});
}

}

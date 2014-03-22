#ifndef SHOPPINGKATACODE_DISCOUNTRULE_H
#define SHOPPINGKATACODE_DISCOUNTRULE_H

#include <string>

namespace ShoppingKataCode {

class DiscountRule
{
public:
	DiscountRule(const std::string& item, int triggerQuantity, int discount);
	int GetApplicableDiscount(const std::string& item);

private:

	void RecordItem();
	bool RuleIsTriggered() const;

	std::string _item;
	int _triggerQuantity;
	int _discount;
	int _count;
};

}

#endif

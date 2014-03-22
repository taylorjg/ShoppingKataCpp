#include "stdafx.h"
#include "DiscountRule.h"

namespace ShoppingKataCode {

DiscountRule::DiscountRule(const std::string& item, int triggerQuantity, int discount) :
	_item(item),
	_triggerQuantity(triggerQuantity),
	_discount(discount),
	_count(0)
{
}

int DiscountRule::GetApplicableDiscount(const std::string& item)
{
	if (item == _item) {
		RecordItem();
		return RuleIsTriggered() ? _discount : 0;
	}

	return 0;
}

void DiscountRule::RecordItem()
{
	_count++;
}

bool DiscountRule::RuleIsTriggered() const
{
	return (_count % _triggerQuantity == 0);
}

}

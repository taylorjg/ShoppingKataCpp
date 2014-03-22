#include "stdafx.h"
#include "Checkout.h"
#include "Basket.h"

namespace ShoppingKataCode {

int Checkout::Process(const Basket& basket)
{
	auto cost =  0;

	basket.ForEachItem([&cost, this](const std::string& item){
		cost += _scanner.Scan(item);
		cost -= _discounter.Discount(item);
	});

	return cost;
}

}

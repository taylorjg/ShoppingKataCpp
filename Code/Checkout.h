#ifndef SHOPPINGKATACODE_CHECKOUT_H
#define SHOPPINGKATACODE_CHECKOUT_H

#include <vector>
#include <string>

#include "Scanner.h"
#include "Discounter.h"

namespace ShoppingKataCode {

class Basket;

class Checkout
{
public:
	int Process(const Basket& basket);

private:
	Scanner _scanner;
	Discounter _discounter;
};

}

#endif

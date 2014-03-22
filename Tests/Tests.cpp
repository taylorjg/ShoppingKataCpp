#include "stdafx.h"
#include "Checkout.h"
#include "Basket.h"

using namespace ShoppingKataCode;

#include <UnitTest++.h>

class ShoppingKataTests
{
protected:
	void AddItemsToBasket(const std::string& items, Basket& basket)
	{
		for (auto c : items) {
			auto item = std::string(1, c); 
			basket.Add(item);
		}
	}

	void CheckCostAfterAddingItems(const std::string& items, int expectedCost)
	{
		AddItemsToBasket(items, _basket);
		auto actualCost = _checkout.Process(_basket);
		CHECK_EQUAL(expectedCost, actualCost);
	}

	Checkout _checkout;
	Basket _basket;
};

TEST_FIXTURE(ShoppingKataTests, EmptyBasket) { CheckCostAfterAddingItems("", 0); }
TEST_FIXTURE(ShoppingKataTests, BasketWithA) { CheckCostAfterAddingItems("A", 50); }
TEST_FIXTURE(ShoppingKataTests, BasketWithB) { CheckCostAfterAddingItems("B", 30); }
TEST_FIXTURE(ShoppingKataTests, BasketWithC) { CheckCostAfterAddingItems("C", 20); }
TEST_FIXTURE(ShoppingKataTests, BasketWithD) { CheckCostAfterAddingItems("D", 15); }
TEST_FIXTURE(ShoppingKataTests, BasketWithAB) { CheckCostAfterAddingItems("AB", 80); }
TEST_FIXTURE(ShoppingKataTests, BasketWithAAA) { CheckCostAfterAddingItems("AAA", 130); }
TEST_FIXTURE(ShoppingKataTests, BasketWithBB) { CheckCostAfterAddingItems("BB", 45); }
TEST_FIXTURE(ShoppingKataTests, BasketWithBBBB) { CheckCostAfterAddingItems("BBBB", 90); }
TEST_FIXTURE(ShoppingKataTests, BasketWithAAABBBBC) { CheckCostAfterAddingItems("AAABBBBC", 130 + 45 + 45 + 20); }
TEST_FIXTURE(ShoppingKataTests, BasketWithBABAABBC) { CheckCostAfterAddingItems("BABAABBC", 130 + 45 + 45 + 20); }
TEST_FIXTURE(ShoppingKataTests, BasketWithBBB) { CheckCostAfterAddingItems("BBB", 45 + 30); }

int _tmain(int argc, _TCHAR* argv[])
{
	return UnitTest::RunAllTests();
}

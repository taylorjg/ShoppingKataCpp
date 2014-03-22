#include "stdafx.h"
#include "Checkout.h"
#include "Basket.h"

using namespace ShoppingKataCode;

#include <UnitTest++.h>

SUITE(ShoppingKataTests)
{
	class ShoppingKataTestsFixture
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

	TEST_FIXTURE(ShoppingKataTestsFixture, BasketWithNothing) { CheckCostAfterAddingItems("", 0); }
	TEST_FIXTURE(ShoppingKataTestsFixture, BasketWithA) { CheckCostAfterAddingItems("A", 50); }
	TEST_FIXTURE(ShoppingKataTestsFixture, BasketWithB) { CheckCostAfterAddingItems("B", 30); }
	TEST_FIXTURE(ShoppingKataTestsFixture, BasketWithC) { CheckCostAfterAddingItems("C", 20); }
	TEST_FIXTURE(ShoppingKataTestsFixture, BasketWithD) { CheckCostAfterAddingItems("D", 15); }
	TEST_FIXTURE(ShoppingKataTestsFixture, BasketWithAB) { CheckCostAfterAddingItems("AB", 80); }
	TEST_FIXTURE(ShoppingKataTestsFixture, BasketWithAAA) { CheckCostAfterAddingItems("AAA", 50 + 50 + 50 - 20); }
	TEST_FIXTURE(ShoppingKataTestsFixture, BasketWithBB) { CheckCostAfterAddingItems("BB", 30 + 30 - 15); }
	TEST_FIXTURE(ShoppingKataTestsFixture, BasketWithBBBB) { CheckCostAfterAddingItems("BBBB", (30 + 30 - 15) + (30 + 30 - 15)); }
	TEST_FIXTURE(ShoppingKataTestsFixture, BasketWithAAABBBBC) { CheckCostAfterAddingItems("AAABBBBC", (50 + 50 + 50 - 20) + (30 + 30 - 15) + (30 + 30 - 15) + 20); }
	TEST_FIXTURE(ShoppingKataTestsFixture, BasketWithBABAABBC) { CheckCostAfterAddingItems("BABAABBC", (50 + 50 + 50 - 20) + (30 + 30 - 15) + (30 + 30 - 15) + 20); }
	TEST_FIXTURE(ShoppingKataTestsFixture, BasketWithBBB) { CheckCostAfterAddingItems("BBB", (30 + 30 - 15) + 30); }
}

int _tmain(int argc, _TCHAR* argv[])
{
	return UnitTest::RunAllTests();
}

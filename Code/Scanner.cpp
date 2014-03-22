#include "stdafx.h"
#include "Scanner.h"

namespace ShoppingKataCode {

int Scanner::Scan(const std::string& item) const
{
	switch (item[0]) {
		case 'A':
			return 50;
		case 'B':
			return 30;
		case 'C':
			return 20;
		case 'D':
			return 15;
		default:
			return 0;
	}
}

}

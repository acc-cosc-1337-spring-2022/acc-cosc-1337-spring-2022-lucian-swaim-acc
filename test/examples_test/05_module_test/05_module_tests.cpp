#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Die class 1 to 6 range checking")
{

	for (int i = 0 ; i < 6 ; i++)
	{
		Die dice;

		dice.roll();

		REQUIRE(true == ((dice.rolled_value() >= 1) && (dice.rolled_value() <= 6)));
	}

}

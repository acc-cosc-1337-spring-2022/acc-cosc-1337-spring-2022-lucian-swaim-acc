#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Die class 1 to 6 range checking")
{
	Die dice;

	for (int i = 0 ; i < 10 ; i++)
	{
		dice.roll();

		REQUIRE(true == ((dice.rolled_value() >= 1) && (dice.rolled_value() <= 6)));
	}
}

TEST_CASE("Roll class 2 to 12 range checking")
{
	Die die01;
	Die die02;
	Roll rollObj(die01, die02);

	for (int i = 0 ; i < 10 ; i++)
	{
		rollObj.roll_die();
		REQUIRE( true == ( (rollObj.roll_value()) >= 2 && (rollObj.roll_value() <= 12) ));
	}
}
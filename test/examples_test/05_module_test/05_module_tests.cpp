#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "phase.h"
#include "come_out_phase.h"
#include "point_phase.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Question 1: Die class 1 to 6 range checking")
{
	Die dice;

	for (int i = 0 ; i < 10 ; i++)
	{
		dice.roll();

		REQUIRE(true == ((dice.rolled_value() >= 1) && (dice.rolled_value() <= 6)));
	}
}

TEST_CASE("Question 2: Roll class 2 to 12 range checking")
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


TEST_CASE("Question 3: Test that shooter returns a roll & roll result between 2-12")
{
	for (int i = 0; i < 10; i++)
	{
		Shooter shootObj;
		Die die1; die1.roll();
		Die die2; die2.roll();
		Roll* rollPtr = new Roll(die1, die2);

		rollPtr = shootObj.throw_die(die1, die2);

		REQUIRE( true == (  (rollPtr->roll_value() >= 2) && (rollPtr->roll_value() <= 12)  ) );
	}
}

TEST_CASE("Question 4: Test that ComeOutPhase get_outcome returns natural/craps/point")
{
	Die die1;
	die1.roll();
	Die die2;
	die2.roll();
	Roll* rollPtr = new Roll(die1, die2);

	ComeOutPhase co_phase;
	//Natural
	rollPtr->set_value(7);
	REQUIRE ( co_phase.get_outcome(rollPtr) == RollOutcome::natural );
	rollPtr->set_value(11);
	REQUIRE ( co_phase.get_outcome(rollPtr) == RollOutcome::natural );

	//Craps
	rollPtr->set_value(2);
	REQUIRE ( co_phase.get_outcome(rollPtr) == RollOutcome::craps );
	rollPtr->set_value(3);
	REQUIRE ( co_phase.get_outcome(rollPtr) == RollOutcome::craps );
	rollPtr->set_value(12);
	REQUIRE ( co_phase.get_outcome(rollPtr) == RollOutcome::craps );	

	//Point
	rollPtr->set_value(1);
	REQUIRE ( co_phase.get_outcome(rollPtr) == RollOutcome::point );
	rollPtr->set_value(4);
	REQUIRE ( co_phase.get_outcome(rollPtr) == RollOutcome::point );
	rollPtr->set_value(5);
	REQUIRE ( co_phase.get_outcome(rollPtr) == RollOutcome::point );	
	rollPtr->set_value(6);
	REQUIRE ( co_phase.get_outcome(rollPtr) == RollOutcome::point );	
	rollPtr->set_value(8);
	REQUIRE ( co_phase.get_outcome(rollPtr) == RollOutcome::point );	
	rollPtr->set_value(9);
	REQUIRE ( co_phase.get_outcome(rollPtr) == RollOutcome::point );	
	rollPtr->set_value(10);
	REQUIRE ( co_phase.get_outcome(rollPtr) == RollOutcome::point );	

	delete rollPtr;
}

TEST_CASE("Question 4: Test that PointPhase get_outcome returns point/seven_out/nopoint")
{
	Die die1;
	die1.roll();
	Die die2;
	die2.roll();
	Roll* rollPtr = new Roll(die1, die2);


	PointPhase pt_phase(9); // Setting 9 to the point number for this test case 
	
	// Check for point
	rollPtr->set_value(9);
	REQUIRE ( pt_phase.get_outcome(rollPtr) == RollOutcome::point );

	// Check for 7 (seven_out)
	rollPtr->set_value(7);
	REQUIRE ( pt_phase.get_outcome(rollPtr) == RollOutcome::seven_out );

	// Check for all no points
	for (int i=2; i <= 12; i++)
	{
		rollPtr->set_value(i);
		if (i != 9 && i != 7) 
		{
			REQUIRE( pt_phase.get_outcome(rollPtr) == RollOutcome::nopoint );
		}
	}

	delete rollPtr;
}

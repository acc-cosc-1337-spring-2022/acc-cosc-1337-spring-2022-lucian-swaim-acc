#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test first player set to X")
{
	TicTacToe game;
	game.start_game("X");

	REQUIRE( game.get_player() == "X" );
}

TEST_CASE("Test first player set to O")
{
	TicTacToe game;
	game.start_game("O");

	REQUIRE( game.get_player() == "O" );
}

TEST_CASE("Test tic tac toe game over if 9 slots are selected")
{
	TicTacToe game;

	game.start_game("X");
	game.mark_board(1);
	REQUIRE(false == game.game_over());
	game.mark_board(2);
	REQUIRE(false == game.game_over());
	game.mark_board(3);
	REQUIRE(false == game.game_over());
	game.mark_board(4);
	REQUIRE(false == game.game_over());
	game.mark_board(5);
	REQUIRE(false == game.game_over());
	game.mark_board(7);
	REQUIRE(false == game.game_over());
	game.mark_board(6);
	REQUIRE(false == game.game_over());
	game.mark_board(9);
	REQUIRE(false == game.game_over());
	game.mark_board(8);
	REQUIRE(true == game.game_over());

	REQUIRE(game.get_winner() == "C");
}

// Test row wins
TEST_CASE("Test win by first row")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(1); // X's turn
	REQUIRE(false == game.game_over());
	game.mark_board(9); // O's turn
	REQUIRE(false == game.game_over());
	game.mark_board(2); // X's turn
	REQUIRE(false == game.game_over());
	game.mark_board(7); // O's turn
	REQUIRE(false == game.game_over());
	game.mark_board(3); // X's turn

	REQUIRE ( true == game.game_over() );
}
TEST_CASE("Test win by second row")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(4); // X's turn
	REQUIRE(false == game.game_over());
	game.mark_board(8); // O's turn
	REQUIRE(false == game.game_over());
	game.mark_board(5); // X's turn
	REQUIRE(false == game.game_over());
	game.mark_board(7); // O's turn
	REQUIRE(false == game.game_over());
	game.mark_board(6); // X's turn

	REQUIRE ( true == game.game_over() );
}
TEST_CASE("Test win by third row")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(7); // X's turn
	REQUIRE(false == game.game_over());
	game.mark_board(1); // O's turn
	REQUIRE(false == game.game_over());
	game.mark_board(8); // X's turn
	REQUIRE(false == game.game_over());
	game.mark_board(2); // O's turn
	REQUIRE(false == game.game_over());
	game.mark_board(9); // X's turn

	REQUIRE ( true == game.game_over() );
}

// Test column wins
TEST_CASE("Test win by first column")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(1); // X's turn
	REQUIRE(false == game.game_over());
	game.mark_board(2); // O's turn
	REQUIRE(false == game.game_over());
	game.mark_board(4); // X's turn
	REQUIRE(false == game.game_over());
	game.mark_board(5); // O's turn
	REQUIRE(false == game.game_over());
	game.mark_board(7); // X's turn

	REQUIRE ( true == game.game_over() );
}
TEST_CASE("Test win by second column")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(2); // X's turn
	REQUIRE(false == game.game_over());
	game.mark_board(3); // O's turn
	REQUIRE(false == game.game_over());
	game.mark_board(5); // X's turn
	REQUIRE(false == game.game_over());
	game.mark_board(9); // O's turn
	REQUIRE(false == game.game_over());
	game.mark_board(8); // X's turn

	REQUIRE ( true == game.game_over() );
}
TEST_CASE("Test win by third column")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(3); // X's turn
	REQUIRE(false == game.game_over());
	game.mark_board(4); // O's turn
	REQUIRE(false == game.game_over());
	game.mark_board(6); // X's turn
	REQUIRE(false == game.game_over());
	game.mark_board(7); // O's turn
	REQUIRE(false == game.game_over());
	game.mark_board(9); // X's turn

	REQUIRE ( true == game.game_over() );
}

//  Test diagonal wins
TEST_CASE("Test win by diagonally from top left")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(1); // X's turn
	REQUIRE(false == game.game_over());
	game.mark_board(8); // O's turn
	REQUIRE(false == game.game_over());
	game.mark_board(5); // X's turn
	REQUIRE(false == game.game_over());
	game.mark_board(7); // O's turn
	REQUIRE(false == game.game_over());
	game.mark_board(9); // X's turn

	REQUIRE ( true == game.game_over() );
}
TEST_CASE("Test win by diagonally from bottom left")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(7); // X's turn
	REQUIRE(false == game.game_over());
	game.mark_board(4); // O's turn
	REQUIRE(false == game.game_over());
	game.mark_board(5); // X's turn
	REQUIRE(false == game.game_over());
	game.mark_board(2); // O's turn
	REQUIRE(false == game.game_over());
	game.mark_board(3); // X's turn

	REQUIRE ( true == game.game_over() );
}
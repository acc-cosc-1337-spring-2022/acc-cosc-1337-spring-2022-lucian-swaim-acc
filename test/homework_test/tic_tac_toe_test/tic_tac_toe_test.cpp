#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test TTT3 first player set to X")
{
	std::unique_ptr<TicTacToe> game;
	game = std::make_unique<TicTacToe3>();
	game->start_game("X");

	REQUIRE( game->get_player() == "X" );
}

TEST_CASE("Test TTT3 irst player set to O")
{
	std::unique_ptr<TicTacToe> game;
	game = std::make_unique<TicTacToe3>();
	game->start_game("O");

	REQUIRE( game->get_player() == "O" );
}

TEST_CASE("Test TTT4 first player set to X")
{
	std::unique_ptr<TicTacToe> game;
	game = std::make_unique<TicTacToe4>();
	game->start_game("X");

	REQUIRE( game->get_player() == "X" );
}

TEST_CASE("Test TTT4 irst player set to O")
{
	std::unique_ptr<TicTacToe> game;
	game = std::make_unique<TicTacToe4>();
	game->start_game("O");

	REQUIRE( game->get_player() == "O" );
}

TEST_CASE("Test TicTacToe3 game over if 9 slots are selected")
{
	std::unique_ptr<TicTacToe> game;
	game = std::make_unique<TicTacToe3>();

	game->start_game("X");
	game->mark_board(1);
	REQUIRE(false == game->game_over());
	game->mark_board(2);
	REQUIRE(false == game->game_over());
	game->mark_board(3);
	REQUIRE(false == game->game_over());
	game->mark_board(4);
	REQUIRE(false == game->game_over());
	game->mark_board(5);
	REQUIRE(false == game->game_over());
	game->mark_board(7);
	REQUIRE(false == game->game_over());
	game->mark_board(6);
	REQUIRE(false == game->game_over());
	game->mark_board(9);
	REQUIRE(false == game->game_over());
	game->mark_board(8);
	REQUIRE(true == game->game_over());

	REQUIRE(game->get_winner() == "C");
}

TEST_CASE("Test TicTacToe4 game over if 16 slots are selected")
{
	std::unique_ptr<TicTacToe> game;
	game = std::make_unique<TicTacToe4>();

	game->start_game("X");
	game->mark_board(1);
	REQUIRE(false == game->game_over());
	game->mark_board(2);
	REQUIRE(false == game->game_over());
	game->mark_board(3);
	REQUIRE(false == game->game_over());
	game->mark_board(4);
	REQUIRE(false == game->game_over());
	game->mark_board(7);
	REQUIRE(false == game->game_over());
	game->mark_board(5);
	REQUIRE(false == game->game_over());
	game->mark_board(8);
	REQUIRE(false == game->game_over());
	game->mark_board(6);
	REQUIRE(false == game->game_over());
	game->mark_board(9);
	REQUIRE(true == game->game_over());
	game->mark_board(11);
	REQUIRE(true == game->game_over());
	game->mark_board(10);
	REQUIRE(true == game->game_over());
	game->mark_board(12);
	REQUIRE(true == game->game_over());
	game->mark_board(14);
	REQUIRE(true == game->game_over());
	game->mark_board(13);
	REQUIRE(true == game->game_over());
	game->mark_board(16);
	REQUIRE(true == game->game_over());
	game->mark_board(15);
	REQUIRE(true == game->game_over());

	REQUIRE(game->get_winner() == "C");
}

// TicTacToe3
// TTT3 Test row wins
TEST_CASE("Test TTT3 win by first row")
{
	std::unique_ptr<TicTacToe> game;
	game = std::make_unique<TicTacToe3>();
	game->start_game("X");

	game->mark_board(1); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(9); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(2); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(7); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(3); // X's turn

	REQUIRE ( true == game->game_over() );
}
TEST_CASE("Test TTT3 win by second row")
{
	std::unique_ptr<TicTacToe> game;
	game = std::make_unique<TicTacToe3>();
	game->start_game("X");

	game->mark_board(4); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(8); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(5); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(7); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(6); // X's turn

	REQUIRE ( true == game->game_over() );
}
TEST_CASE("Test TTT3 win by third row")
{
	std::unique_ptr<TicTacToe> game;
	game = std::make_unique<TicTacToe3>();
	game->start_game("X");

	game->mark_board(7); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(1); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(8); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(2); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(9); // X's turn

	REQUIRE ( true == game->game_over() );
}

// TTT3 Test column wins
TEST_CASE("Test TTT3 win by first column")
{
	std::unique_ptr<TicTacToe> game;
	game = std::make_unique<TicTacToe3>();
	game->start_game("X");

	game->mark_board(1); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(2); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(4); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(5); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(7); // X's turn

	REQUIRE ( true == game->game_over() );
}
TEST_CASE("Test TTT3 win by second column")
{
	std::unique_ptr<TicTacToe> game;
	game = std::make_unique<TicTacToe3>();
	game->start_game("X");

	game->mark_board(2); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(3); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(5); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(9); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(8); // X's turn

	REQUIRE ( true == game->game_over() );
}
TEST_CASE("Test TTT3 win by third column")
{
	std::unique_ptr<TicTacToe> game;
	game = std::make_unique<TicTacToe3>();
	game->start_game("X");

	game->mark_board(3); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(4); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(6); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(7); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(9); // X's turn

	REQUIRE ( true == game->game_over() );
}

//  TTT3 Test diagonal wins
TEST_CASE("Test TTT3 win by diagonally from top left")
{
	std::unique_ptr<TicTacToe> game;
	game = std::make_unique<TicTacToe3>();
	game->start_game("X");

	game->mark_board(1); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(8); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(5); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(7); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(9); // X's turn

	REQUIRE ( true == game->game_over() );
}
TEST_CASE("Test TTT3 win by diagonally from bottom left")
{
	std::unique_ptr<TicTacToe> game;
	game = std::make_unique<TicTacToe3>();
	game->start_game("X");

	game->mark_board(7); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(4); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(5); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(2); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(3); // X's turn

	REQUIRE ( true == game->game_over() );
}

// TicTacToe 4
// TTT4 Test row wins
TEST_CASE("Test TTT4 win by first row")
{
	std::unique_ptr<TicTacToe> game;
	game = std::make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(1); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(9); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(2); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(7); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(3); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(12); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(4); // X's turn

	REQUIRE ( true == game->game_over() );
}
TEST_CASE("Test TTT4 win by second row")
{
	std::unique_ptr<TicTacToe> game;
	game = std::make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(5); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(1); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(6); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(2); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(7); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(12); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(8); // X's turn

	REQUIRE ( true == game->game_over() );
}
TEST_CASE("Test TTT4 win by third row")
{
	std::unique_ptr<TicTacToe> game;
	game = std::make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(9); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(1); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(10); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(2); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(11); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(3); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(12); // X's turn

	REQUIRE ( true == game->game_over() );
}
TEST_CASE("Test TTT4 win by fourth row")
{
	std::unique_ptr<TicTacToe> game;
	game = std::make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(13); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(1); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(14); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(8); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(15); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(3); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(16); // X's turn

	REQUIRE ( true == game->game_over() );
}

// TTT4 Test column wins
TEST_CASE("Test TTT4 win by first column")
{
	std::unique_ptr<TicTacToe> game;
	game = std::make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(1); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(2); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(5); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(3); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(9); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(4); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(13); // X's turn

	REQUIRE ( true == game->game_over() );
}
TEST_CASE("Test TTT4 win by second column")
{
	std::unique_ptr<TicTacToe> game;
	game = std::make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(2); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(1); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(6); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(3); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(10); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(8); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(14); // X's turn

	REQUIRE ( true == game->game_over() );
}
TEST_CASE("Test TTT4 win by third column")
{
	std::unique_ptr<TicTacToe> game;
	game = std::make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(3); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(1); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(7); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(2); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(11); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(14); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(15); // X's turn

	REQUIRE ( true == game->game_over() );
}
TEST_CASE("Test TTT4 win by fourth column")
{
	std::unique_ptr<TicTacToe> game;
	game = std::make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(4); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(2); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(8); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(6); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(12); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(7); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(16); // X's turn

	REQUIRE ( true == game->game_over() );
}

// TTT4 Test diagonal wins
TEST_CASE("Test TTT4 win diagonally from top left")
{
	std::unique_ptr<TicTacToe> game;
	game = std::make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(1); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(2); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(6); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(4); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(11); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(8); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(16); // X's turn

	REQUIRE ( true == game->game_over() );
}
TEST_CASE("Test TTT4 win diagonally from top right")
{
	std::unique_ptr<TicTacToe> game;
	game = std::make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(4); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(2); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(7); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(9); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(10); // X's turn
	REQUIRE(false == game->game_over());
	game->mark_board(12); // O's turn
	REQUIRE(false == game->game_over());
	game->mark_board(13); // X's turn

	REQUIRE ( true == game->game_over() );
}

// TicTacToeManager
TEST_CASE("Test TT3 get_winner_total manager function")
{
	/* 	
	Test TicTacToeManager's get_winner_total function
	Simulate playing 3 or more games with X, O, & C as winners
	Verify that x_win, o_win, & ties tally correctly
	*/

	TicTacToeManager manager;
	std::unique_ptr<TicTacToe> game;
	game = std::make_unique<TicTacToe3>();

//Game 1: X Wins
	game->start_game("X");

	game->mark_board(1); // X's turn
	game->mark_board(9); // O's turn
	game->mark_board(2); // X's turn
	game->mark_board(7); // O's turn
	game->mark_board(3); // X's turn
	game->game_over();
	REQUIRE( game->get_winner() == "X");
	manager.save_game(game);

// Game 2: O Wins
	game->start_game("O");

	game->mark_board(1); // O's turn
	game->mark_board(9); // X's turn
	game->mark_board(2); // O's turn
	game->mark_board(7); // X's turn
	game->mark_board(3); // O's turn
	game->game_over();
	REQUIRE ( game->get_winner() == "O");
	manager.save_game(game);

// Game 3: Tie 
	game->start_game("X");

	game->mark_board(1); // O's turn
	game->mark_board(2); // X's turn
	game->mark_board(3); // O's turn
	game->mark_board(7); // X's turn
	game->mark_board(8); // O's turn
	game->mark_board(9); // X's turn
	game->mark_board(4); // O's turn
	game->mark_board(5); // X's turn
	game->mark_board(6); // O's turn
	game->game_over();
	REQUIRE ( game->get_winner() == "C");
	manager.save_game(game);

// Check manager totals
	int o_wins = 0;
	int x_wins = 0;
	int ties = 0;
	manager.get_winner_totals(o_wins, x_wins, ties);

	REQUIRE(o_wins == 1);
	REQUIRE(x_wins == 1);
	REQUIRE(ties == 1);
}
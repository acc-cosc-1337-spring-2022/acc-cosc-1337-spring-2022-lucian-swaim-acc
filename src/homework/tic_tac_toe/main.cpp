#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

using std::cout; using std::cin; using std::string;

int main() 
{
	std::unique_ptr<TicTacToe> game;
	string first_player;
	int size_choice;
	char choice;

	TicTacToeData data;

	TicTacToeManager manager(data);
	int o_wins = 0;
	int x_wins = 0;
	int ties = 0;

	do
	{
		// Game type (3x3 or 4x4) selection & validation
		cout << "Play on a 3x3 grid or a 4x4? (enter 3 or 4):   ";
		cin >> size_choice;
		while ( (size_choice != 3) && (size_choice != 4) )
		{
			cout << "Invalid input. Please enter 3 or 4.\n";
			cin >> size_choice;
		}
		// Generating the game object
		if 		(size_choice == 3)
		{
			game = std::make_unique<TicTacToe3>();
		}
		else if (size_choice == 4)
		{
			game = std::make_unique<TicTacToe4>();
		}
		
		// First player selection & validation
		cout << "Enter first player (X or O): ";
		cin >> first_player;
		while ( (first_player != "X") && (first_player != "O") )
		{
			cout << "Invalid input. Please enter X or O.\n";
			cin >> first_player;
		}
		
		game->start_game(first_player);

		while(game->game_over() == false)
		{
			cin >> *game;
			cout << *game;

			if (game->game_over() == true)
			{
				if (game->get_winner() == "C")
				{
					cout << "Tie!\n";
				}
				else
				{
					cout << game->get_winner() << " wins!\n\n";
				}
			}
		}

		manager.save_game(game);

		// Get & display the current score
		manager.get_winner_totals(o_wins, x_wins, ties);
		cout << "Score:\n" << 
		"X:    " << x_wins << "\n" <<
		"O:    " << o_wins << "\n" <<
		"Ties: " << ties << "\n\n";

		cout << "Play another? (Y/N): ";
		cin >> choice;
		cout << "\n";

	} while (choice == 'Y' || choice == 'y');

	cout << manager;
	
	return 0;
}
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

using std::cout; using std::cin; using std::string;

int main() 
{
	TicTacToe game;
	string first_player;
	char choice;

	TicTacToeManager manager;
	int o_wins = 0;
	int x_wins = 0;
	int ties = 0;

	do
	{
		cout << "Enter first player (X or O): ";
		cin >> first_player;

		while ( (first_player != "X") && (first_player != "O") )
		{
			cout << "Invalid input. Please choose X or O.\n";
			cin >> first_player;
		}

		game.start_game(first_player);

		while(game.game_over() == false)
		{

			cin >> game;
			cout << game;

			if (game.game_over() == true)
			{
				if (game.get_winner() == "C")
				{
					cout << "Tie!\n";
				}
				else
				{
					cout << game.get_winner() << " wins!\n\n";
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
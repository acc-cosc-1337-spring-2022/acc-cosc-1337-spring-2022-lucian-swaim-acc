#include "tic_tac_toe.h"

using std::cout; using std::cin; using std::string;

int main() 
{
	TicTacToe game;
	string first_player;
	char choice;

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

		int position;
		while(game.game_over() == false)
		{
			cout << "Enter position [1-9]: ";
			cin >> position;

			while ( (position < 1) || (position > 9) )
			{
				cout << "Invalid input. Please pick a position between 1 and 9 (inclusive)\n";
				cin >> position;
			}


			game.mark_board(position);
			game.display_board();

			if (game.game_over() == true)
			{
				if (game.get_winner() == "C")
				{
					cout << "Tie!\n";
				}
				else
				{
					cout << game.get_winner() << " wins!\n";
				}
			}
		}

		cout << "Play another? (Y/N): ";
		cin >> choice;

	} while (choice == 'Y' || choice == 'y');
	
	return 0;
}
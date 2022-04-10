//cpp
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

void TicTacToeManager::update_winner_count(std::string winner)
{
    if (winner == "X")
    {
        x_wins++;
    }
    else if (winner == "O")
    {
        o_wins++;
    }
    else
    {
        ties++;
    }
}

void TicTacToeManager::get_winner_totals(int& o, int& x, int& t)
{
    o = o_wins;
    x = x_wins;
    t = ties;
}

void TicTacToeManager::save_game(TicTacToe b)
{
    games.push_back(b);
    update_winner_count(b.get_winner());
}

// Operator Overloaders
std::ostream& operator<<(std::ostream& out, TicTacToeManager& manager)
{   
    cout << "===== Game History =====\n";
    for (int ele = 0; ele < manager.games.size(); ele++)
    {
        cout << "=== Game #" << ele+1 << " ===\n";
        out << manager.games[ele];
    }
    return out;
}
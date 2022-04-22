//cpp
#include "tic_tac_toe_data.h"

void TicTacToeData::save_games(const std::vector<std::unique_ptr<TicTacToe>>& games)
{
    std::ofstream outfile;
    outfile.open(FILE_NAME);

    if (outfile.is_open())
    {
        for (auto& game : games)
        {
            for (auto& peg : game->get_pegs())
            {
                outfile << peg;
            }

            outfile << game->get_winner();
            outfile << "\n"; 
        }
    }

    outfile.close();
}

std::vector<std::unique_ptr<TicTacToe>> TicTacToeData::get_games()
{
    std::vector<std::unique_ptr<TicTacToe>> boards;
    std::ifstream inpfile;
    inpfile.open(FILE_NAME);

    std::string line;

    if (inpfile.is_open())
    {
        while (std::getline(inpfile, line))
        {
            std::vector<std::string> pegs;

            for (auto i = 0; i < (line.size() - 1); ++i)
            {
                std::string ch(1, line[i]);
                pegs.push_back(ch);
            }

            std::string winner_char{line[line.size() - 1]};
            std::unique_ptr<TicTacToe> board;

            if      (pegs.size() == 9)
            {
                board = std::make_unique<TicTacToe3>(pegs, winner_char);
            }
            else if (pegs.size() == 16)
            {
                board = std::make_unique<TicTacToe4>(pegs, winner_char);
            }

            boards.push_back(std::move(board));
        }

        inpfile.close();
    }

    return boards;
}
//h
#include <vector>
#include <string>
#include <memory>
#include "tic_tac_toe.h"


//Header Guards
#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

class TicTacToeManager
{
private:
    std::vector<std::unique_ptr<TicTacToe>> games;
    int x_wins = 0;
    int o_wins = 0;
    int ties = 0;

    void update_winner_count(std::string);

public:
    void get_winner_totals(int&, int&, int&);
    void save_game(std::unique_ptr<TicTacToe>&);
    friend std::ostream& operator<<(std::ostream&, TicTacToeManager&);
};

#endif //TIC_TAC_TOE_MANAGER_H
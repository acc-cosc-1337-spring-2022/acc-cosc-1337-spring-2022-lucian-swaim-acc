//h
#include <vector>
#include <string>
#include <memory>
#include "tic_tac_toe.h"
#include "tic_tac_toe_data.h"


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
    TicTacToeData data;

    void update_winner_count(std::string);

public:
    TicTacToeManager() = default; // constructor
    TicTacToeManager(TicTacToeData& d);
    void get_winner_totals(int&, int&, int&);
    void save_game(std::unique_ptr<TicTacToe>&);
    friend std::ostream& operator<<(std::ostream&, TicTacToeManager&);
    ~TicTacToeManager();
};

#endif //TIC_TAC_TOE_MANAGER_H
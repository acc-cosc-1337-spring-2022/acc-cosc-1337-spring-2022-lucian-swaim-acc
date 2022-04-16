//h
#include <iostream>
using std::cout;

#include <string>
#include <vector>


//Header Guards
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

class TicTacToe
{
public:
    TicTacToe(int); // Constructor
    bool game_over();
    void start_game(std::string first_player);
    void mark_board(int position);
    std::string get_player()const{return player;}
    std::string get_winner(){return winner;}

    //Operator overloaders
    friend std::istream& operator>>(std::istream&, TicTacToe&);
    friend std::ostream& operator<<(std::ostream&, const TicTacToe&);

protected:
    std::vector<std::string> pegs;

    virtual bool check_row_win();
    virtual bool check_column_win();
    virtual bool check_diagonal_win();

private: 
    //Private vars
    std::string player;
    std::string winner;

    // Private funcs
    void set_winner();
    void set_next_player();
    bool check_board_full();
    void clear_board();
};

#endif // TIC_TAC_TOE_H

// Deprecated member function of older version
//void display_board()const;
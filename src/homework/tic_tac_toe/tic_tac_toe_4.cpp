#include "tic_tac_toe_4.h"

/*
class function check_column_win
Win by column if and return true if (each column index)
0, 4, 8, 12
1, 5, 9, 13
2, 6, 10, 14
3, 7, 11, 15
else
false
*/
bool TicTacToe4::check_column_win()
{
    if      ( (pegs[0] == pegs[4]) && (pegs[0] == pegs[8]) && (pegs[0] == pegs[12]) )
    {
        return true;
    }
    else if ( (pegs[1] == pegs[5]) && (pegs[1] == pegs[9]) && (pegs[1] == pegs[13]) )
    {
        return true;
    }
    else if ( (pegs[2] == pegs[6]) && (pegs[2] == pegs[10]) && (pegs[2] == pegs[14]) )
    {
        return true;
    }
    else if ( (pegs[3] == pegs[7]) && (pegs[3] == pegs[11]) && (pegs[3] == pegs[15]) )
    {
        return true;
    }
    else
    {
        return false;
    }
}



/*
class function check_row_win
Win by row if
0, 1,  2,  3 are equal
4, 5,  6,  7 are equal
8, 9, 10, 11 are equal 
12,13,14, 15 are equal
else
false
*/
bool TicTacToe4::check_row_win()
{
    if      ( (pegs[0] == pegs[1]) && (pegs[0] == pegs[2]) && (pegs[0] == pegs[3]) )
    {
        return true;
    }
    else if ( (pegs[4] == pegs[5]) && (pegs[4] == pegs[6]) && (pegs[4] == pegs[7]) )
    {
        return true;
    }
    else if ( (pegs[8] == pegs[9]) && (pegs[8] == pegs[10]) && (pegs[8] == pegs[11]) )
    {
        return true;
    }
    else if ( (pegs[12] == pegs[13]) && (pegs[12] == pegs[14]) && (pegs[12] == pegs[15]) )
    {
        return true;
    }
    else
    {
        return false;
    }
}


/*
class function check_diagonal_win
Win diagonally if
0, 5, 10, 15 are equal
3, 6, 9, 12 are equal
else
false
*/
bool TicTacToe4::check_diagonal_win()
{
    if      ( (pegs[0] == pegs[5]) && (pegs[0] == pegs[10]) && (pegs[0] == pegs[15]) )
    {
        return true;
    }
    else if ( (pegs[3] == pegs[6]) && (pegs[3] == pegs[9]) && (pegs[3] == pegs[12]) )
    {
        return true;
    }
    else
    {
        return false;
    }
}
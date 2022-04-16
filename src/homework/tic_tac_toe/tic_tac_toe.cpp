//cpp
#include "tic_tac_toe.h"

using std::string; using std::cout; using std::cin;

TicTacToe::TicTacToe(int size) : pegs(size^size, " ") // Constructor
{
    /* 
    If you're wondering why there's no code in here:
    The Constructor initializes the pegs vector in the line above ; no other code needed

    Example: SomeConstructor(int s) :some_vector(s*s, " " ){}
    //this will initialize some_vector to s*s elements of " " 
    */
}

bool TicTacToe::game_over()
{
    if      (check_row_win() == true)
    {
        set_winner();
        return true;
    }
    else if (check_column_win() == true)
    {
        set_winner();
        return true;
    }
    else if (check_diagonal_win() == true)
    {
        set_winner();
        return true;
    }
    else if (check_board_full() == true)
    {
        winner = "C";
        return true;
    }
    else
    {
        return false;
    }
    
    
}

void TicTacToe::start_game(string first_player)
{
    player = first_player;
    clear_board();
}

void TicTacToe::mark_board(int position)
{
    pegs[position - 1] = player;
    set_next_player();
}

void TicTacToe::set_next_player()
{
    if(player == "X")
    {
        player = "O";
    }
    else
    {
        player = "X";
    }
}

bool TicTacToe::check_board_full()
{
    for(auto peg: pegs)
    {
        if (peg == " ")
        {
            return false;
        } 
    }

    return true;
}

void TicTacToe::clear_board()
{
    for (auto& peg: pegs)
    {
        peg = " ";
    }
}

bool TicTacToe::check_row_win()
{
    return false;
/* Deprecated code
    // X row win
    if      ( (pegs[0] == "X") && (pegs[1] == "X") && (pegs[2] == "X") )
    {
        return true;
    }
    else if ( (pegs[3] == "X") && (pegs[4] == "X") && (pegs[5] == "X") )
    {
        return true;
    }
    else if ( (pegs[6] == "X") && (pegs[7] == "X") && (pegs[8] == "X") )
    {
        return true;
    }
    // O row win
    else if ( (pegs[0] == "O") && (pegs[1] == "O") && (pegs[2] == "O") )
    {
        return true;
    }
    else if ( (pegs[3] == "O") && (pegs[4] == "O") && (pegs[5] == "O") )
    {
        return true;
    }
    else if ( (pegs[6] == "O") && (pegs[7] == "O") && (pegs[8] == "O") )
    {
        return true;
    }
    else
    {
        return false;
    } */
}

bool TicTacToe::check_column_win()
{
    return false;
/* Deprecated code
    // X column win
    if      ( (pegs[0] == "X") && (pegs[3] == "X") && (pegs[6] == "X") )
    {
        return true;
    }
    else if ( (pegs[1] == "X") && (pegs[4] == "X") && (pegs[7] == "X") )
    {
        return true;
    }
    else if ( (pegs[2] == "X") && (pegs[5] == "X") && (pegs[8] == "X") )
    {
        return true;
    }
    // O column win
    else if ( (pegs[0] == "O") && (pegs[3] == "O") && (pegs[6] == "O") )
    {
        return true;
    }
    else if ( (pegs[1] == "O") && (pegs[4] == "O") && (pegs[7] == "O") )
    {
        return true;
    }
    else if ( (pegs[2] == "O") && (pegs[5] == "O") && (pegs[8] == "O") )
    {
        return true;
    }
    else
    {
        return false;
    }*/
}

bool TicTacToe::check_diagonal_win()
{
    return false;
/*  Deprecated code
    // X diagonal win
    if      ( (pegs[0] == "X") && (pegs[4] == "X") && (pegs[8] == "X") )
    {
        return true;
    }
    else if ( (pegs[2] == "X") && (pegs[4] == "X") && (pegs[6] == "X") )
    {
        return true;
    }
    // O diagonal win
    else if ( (pegs[0] == "O") && (pegs[4] == "O") && (pegs[8] == "O") )
    {
        return true;
    }
    else if ( (pegs[2] == "O") && (pegs[4] == "O") && (pegs[6] == "O") )
    {
        return true;
    }
    else
    {
        return false;
    } */
}

void  TicTacToe::set_winner()
{
    if (player == "X")
    {
        winner = "O";
    }
    else
    {
        winner = "X";
    }
    
}

// Operator Overloaders
std::ostream& operator<<(std::ostream& out, const TicTacToe& game) // cout overloader
{
    if      (game.pegs.size() == 9)
    {
        for(int i=0 ; i < 9 ; i+=3)
        {
            cout << game.pegs[i] << "|" << game.pegs[i+1] << "|" << game.pegs[i+2] << "\n";
        }    
    }
    else if (game.pegs.size() == 16)
    {
        for(int i=0 ; i < 16 ; i+=4)
        {
        cout << game.pegs[i] << "|" << game.pegs[i+1] << "|" << game.pegs[i+2] << "|" << game.pegs[i+3] << "\n";
        }    
    }
    return out;
}

std::istream& operator>>(std::istream& inp, TicTacToe& game) // cin overloader
{
    int position;

    if      (game.pegs.size() == 9)
    { 
        cout << "Enter position [1-9]: ";
        inp >> position;
        while ( (position < 1) || (position > 9) )
        {
            cout << "Invalid input. Please pick a position between 1 and 9 (inclusive)\n";
            inp >> position;
        }
        game.mark_board(position);
    }

    else if (game.pegs.size() == 16)
    {
        cout << "Enter position [1-16]: ";
        inp >> position;
        while ( (position < 1) || (position > 16) )
        {
            cout << "Invalid input. Please pick a position between 1 and 16 (inclusive)\n";
            inp >> position;
        }
        game.mark_board(position);
    }
    
    return inp;
}

// Deprecated member function of older version
/* void TicTacToe::display_board()const
{
    for(int i=0 ; i < 9 ; i+=3)
    {
        cout << pegs[i] << "|" << pegs[i+1] << "|" << pegs[i+2] << "\n";
    }
} */
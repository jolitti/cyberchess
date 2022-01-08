#ifndef CHESS_H
#define CHESS_H

#include <string>
using std::string;


// Collection of all chess-related names
namespace chess
{   
    // Letters for the x coordinates on the chessboard
    const string LETTERS = "ABCDEFGH";
    // Number of cells on a side of the board
    const int BOARD_SIZE = 8;
    // Standard representation of a position outside the board (e.g. Z9)
    const string INVALID_POS = "INVALID";

    // The possible colors a piece can have
    enum color
    {
        black,
        white
    };

    // The specific type of piece
    enum piece
    {
        pawn,
        bishop,
        knight,
        rook,
        queen,
        king
    };
}

#endif
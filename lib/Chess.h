#ifndef CHESS_H
#define CHESS_H

#include <string>
#include <map>
using std::string, std::map;


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

    // Map from initial letter (in italian) to piece
    const map<string,piece> LETTER_TO_PIECE_IT = 
    {
        // Uppercase
        {"P",pawn},
        {"A",bishop},
        {"C",knight},
        {"T",rook},
        {"D",queen},
        {"R",king},

        // Lowercase
        {"p",pawn},
        {"a",bishop},
        {"c",knight},
        {"t",rook},
        {"d",queen},
        {"r",king}
    };
}

#endif
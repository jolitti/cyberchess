#ifndef CHESS_H
#define CHESS_H

#include <string>
#include <map>
using std::string, std::map, std::reference_wrapper;

#include "point/Point.h"

// Collection of all chess-related names
namespace chess
{   
    // Predefinitions to allow cyclic reference
    class Piece;
    class Board;
    class Move;

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

#include "board/Board.h"
#include "move/Move.h"
#include "piece/Piece.h"

#endif
// Marco Giacomin 2016269

#ifndef CHESS_H
#define CHESS_H

#include <string>
#include <map>
#include <memory>
#include <vector>
using std::string, std::map, std::unique_ptr, std::vector;

#include "point/Point.h"



// Collection of all chess-related names
namespace chess
{   
    // Predefinitions to allow cyclic reference
    //class Piece;
    //class Board;
    //class Move;
    //class Player;

    // The possible colors a piece can have
    enum color
    {
        black,
        white
    };
    inline color oppositeColor(color c) { return (c == color::white ? color::black : color::white); }
    inline color colorOf(char c) { return (isupper(c)? color::black : color::white); }

    // The specific type of piece
    enum pieceType
    {
        none,
        pawn,
        bishop,
        knight,
        rook,
        queen,
        king
    };

    // Pair of piece type and color
    // Intellisense bug: this description is not displayed
    typedef pair<pieceType,color> piece;

    // Map from initial letter (in italian) to piece
    const map<char,pieceType> LETTER_TO_PIECE_IT = 
    {
        // Empty space
        {' ',none},

        // Uppercase (black)
        {'P',pawn},
        {'A',bishop},
        {'C',knight},
        {'T',rook},
        {'D',queen},
        {'R',king},

        // Lowercase (white)
        {'p',pawn},
        {'a',bishop},
        {'c',knight},
        {'t',rook},
        {'d',queen},
        {'r',king}
    };

    const map<pieceType,char> PIECE_TO_LETTER_IT = 
    {
        // None
        {none, ' '},

        // Actual pieces (lowercase)
        {pawn, 'p'},
        {bishop, 'a'},
        {knight, 'c'},
        {rook, 't'},
        {queen, 'd'},
        {king, 'r'}
    };

    // Types of pieces a pawn may be promoted to
    const vector<pieceType> POSSIBLE_PROMOTIONS =
    { knight,bishop,rook,queen };

    const vector<Point> KNIGHT_MOVES = 
    {
        {1, 2},
        {2, 1},
        {-1, 2},
        {-2, 1},
        {1,-2},
        {2,-1},
        {-1,-2},
        {-2,-1}
    };

    // Horizontal and vertical basic movements, for move calculations
    const vector<Point> ORTHOGONALS =
    {
        {0,1}, {0,-1}, {-1,0}, {1,0}
    };

    // Diagonal basic movements, for move calculations
    const vector<Point> DIAGONALS =
    {
        {1,1},
        {-1,1},
        {-1,-1},
        {1,-1}
    };
}

//#include "piece/Piece.h"
//#include "board/Board.h"
//#include "move/Move.h"
//#include "history/History.h"
//#include "movecalc/Movecalc.h"


#endif /* CHESS_H */

#ifndef CHESS_H
#define CHESS_H

#include <string>
using std::string;

namespace chess
{
    const string LETTERS = "ABCDEFGH";
    const int BOARD_SIZE = 8;
    const string INVALID_POS = "INVALID";

    enum color
    {
        black,
        white
    };

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
#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "../Chess.h"

using  std::vector;

namespace chess
{

    class Board
    {  
    private:
        // Every piece on the board, mapped to their position
        vector<vector<Piece*>> pieces;
        // History of the moves taken on the board
        vector<Move> moves;
    
    public:
        // Default constructor (initial state of a chess board)
        Board();

        // Build board based on string representation
        Board(const string& seed);

        // Get corresponding piece in the 2d vector (or null if place is empty)
        Piece& getPieceAt(const Point& position) const;
    };
}
#endif
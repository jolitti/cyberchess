#ifndef BOARD_H
#define BOARD_H

#include <unordered_map>
#include <vector>
#include "../Chess.h"
#include "../point/Point.h"
#include "../piece/Piece.h"
#include "../move/Move.h"

using std::unordered_map, std::vector;

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
    };
}
#endif
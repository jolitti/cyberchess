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

        //print current state of the board
        void print() const;

        //add a new move into "moves" vector  
        void save_move(Move move);

        //returns the size of vector moves
        unsigned int get_history_size() const;

        //given index, returns associated move
        Move get_move(unsigned int index) const;

        //updates pieces vector with the given move: returns false if start is empty
        bool set_move(Point start, Point end); 



    };
}
#endif
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

<<<<<<< HEAD
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



=======
        // Build board based on string representation
        Board(const string& seed);

        // Get corresponding piece in the 2d vector (or null if place is empty)
        Piece& getPieceAt(const Point& position) const;
>>>>>>> marco
    };
}
#endif
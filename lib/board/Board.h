// Marco Giacomin 2016269 

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "../Chess.h"

#include <iostream>
#include <string>
using std::ostream, std::string, std::vector;

namespace chess
{

    class Board
    {  
    private:

        // Every piece on the board, mapped to their position
        vector<vector<piece>> pieces;

        // History of the moves taken on the board
        vector<Move> moveHistory;

        // Get possible moves of this specific color
        vector<Move> getMoves(color movingColor) const;
    public:
        // Default constructor (initial state of a chess board)
        Board();

        // Build board based on string representation
        Board(const string& seed);

        // Get corresponding piece in the 2d vector (or null if place is empty)
        piece getPieceAt(const Point& position) const;

        // Set piece in corresponding position, return old value
        piece setPieceAt(const Point& position, piece newValue);

        // Remove piece in corresponding position, return old value
        piece removePieceAt(const Point& position);

        // Color of the piece that has to move
        color getMovingColor() const;
        

        // Apply function f to every cell on the board, row-first
        template <typename Function>
        void forEachCell(Function f); 

        // Get moves of the pieces of the color corresponding to the turn
        vector<Move> getMoves() const;

        // Get an immutable reference to the vector of past moves
        const vector<Move>& getMoveHistory() const;

        // Push move onto list of past moves,
        // then set color of next move to opposite of this one
        void addMove(Move m);

        //String rappresentation of the board
        string toString() const;

        


        // DO NOT IMPLEMENT YET
        // detect checkmate
        //bool checkmate() const;
        // DO NOT IMPLEMENT YET
        // get checkmate color (exepts if no checkmate)
        //color checkmateColor() const;

    };
}

// Print result of toString() to ostream
ostream& operator<< (ostream& o, const chess::Board b);
#endif /* BOARD_H */

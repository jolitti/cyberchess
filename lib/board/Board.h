#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "../Chess.h"

using std::vector;

namespace chess
{

    class Board
    {  
    private:
        // Color of the next piece that has to move
        chess::color toMove;

        // Every piece on the board, mapped to their position
        vector<vector<Piece*>> pieces;
        // History of the moves taken on the board
        vector<Move> moves;

        // Get moves of this specific color
        vector<Move> getMoves(color movingColor) const;
    public:
        // Default constructor (initial state of a chess board)
        Board();

        // Build board based on string representation
        Board(const string& seed);

        // Get corresponding piece in the 2d vector (or null if place is empty)
        Piece* getPieceAt(const Point& position) const;

        // Set piece in corresponding position, return old value
        Piece* setPieceAt(const Point& position, Piece& newValue);

        // Remove piece in corresponding position, return old value
        Piece* removePieceAt(const Point& position);

        // Color of the piece that has to move
        color getMovingColor() const;
        

        // Apply function f to every cell on the board, row-first
        template <typename Function>
        void forEachCell(Function f); 

        // Get moves of the pieces of the color corresponding to the turn
        vector<Move> getMoves() const;


        // DO NOT IMPLEMENT YET
        // detect checkmate
        bool checkmate() const;
        // DO NOT IMPLEMENT YET
        // get checkmate color (exepts if no checkmate)
        color checkmateColor() const;

    };
}
#endif
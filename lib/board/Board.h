// Marco Giacomin 2016269 

#ifndef BOARD_H
#define BOARD_H

#include "../Chess.h"

#include <iostream>
#include <string>

using std::ostream, std::string;

namespace chess
{
    // Mutable representation of chess pieces on a 8x8 grid
    class Board
    {  
    private:

        // Every piece on the board, mapped to their position
        vector<vector<piece>> pieces;

        // History of the moves taken on the board
        //vector<Move> moveHistory;

        // Get possible moves of this specific color
        //vector<unique_ptr<Move>> getMoves(color movingColor) const;
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
        //color getMovingColor() const;
        

        // Apply function f to every piece on the board, row-first
        template <typename Function>
        void forEachPiece(Function f); 

        // Apply function f to every Point on the board, row first
        template <typename Function>
        void forEachPosition(Function f);

        // Get moves of the pieces of the color corresponding to the turn
        //vector<unique_ptr<Move>> getMoves() const;

        // Get an immutable reference to the vector of past moves
        //const vector<unique_ptr<Move>>& getMoveHistory() const;

        // Push move onto list of past moves,
        // then set color of next move to opposite of this one
        //void addMove(unique_ptr<Move> m);

        //String rappresentation of the board
        string toString();

        // Like toString(), but with row and column indicators
        string toVerboseString() const;

        


        // DO NOT IMPLEMENT YET
        // detect checkmate
        //bool checkmate() const;
        // DO NOT IMPLEMENT YET
        // get checkmate color (exepts if no checkmate)
        //color checkmateColor() const;

        //~Board();
    };

    char pieceToLetterIt(const piece& p);
}

// Print result of toVerboseString() to ostream
ostream& operator<< (ostream& o, const chess::Board b);
#endif /* BOARD_H */

#ifndef PIECE_H
#define PIECE_H

#include "../Chess.h"

#include <string>
#include <vector>
using std::string, std::vector;

namespace chess
{
    // Abstract class to be derived into specific pieces
    class Piece
    {
    protected:
        color pieceColor;
        Point position;
        Board& boardRef;

        
    public:
        Piece();
        /* Piece(Point _position, color _piececolor, Board& _boardRef):
        position{_position},pieceColor{_piececolor},boardRef{_boardRef} {}; */

        virtual piece getPieceType() const = 0;
        color getColor() const { return pieceColor; }

        // Get character that represents this piece (e.g p for a black pawn)
        virtual char toChar() const = 0;

        // Get list of all legal moves this piece can perform
        virtual vector<Move> getMoves() const = 0;

        // Get a copy of the piece's position
        Point getPos() const { return position; }
    };
}

#endif
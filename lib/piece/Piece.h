#ifndef PIECE_H
#define PIECE_H

#include "../Chess.h"
#include "../point/Point.h"
#include "../board/Board.h"

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
        virtual piece getPieceType() const = 0;

        // Get character that represents this piece (e.g p for a black pawn)
        virtual char toString() const = 0;

        // Get list of all legal moves this piece can perform
        virtual vector<Move> getMoves() const = 0;
    };
}

#endif
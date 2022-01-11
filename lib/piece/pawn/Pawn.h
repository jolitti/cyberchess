#ifndef PAWN_H
#define PAWN_H

#include "../Piece.h"

namespace chess
{
    // Implementation of the Piece class into a standard chess Pawn
    class Pawn : public Piece
    {
    public:
        Pawn(Point _position, color _pieceColor, Board& _boardRef);

        piece getPieceType() const override;

        char toChar() const override;

        vector<Move> getMoves() const override;
    };
}

#endif
#include "Pawn.h"

namespace chess
{
    Pawn::Pawn(Point _position, color _pieceColor, Board& _boardRef)
    {
        position = _position;
        pieceColor = _pieceColor;
        boardRef = _boardRef;
    }

    piece Pawn::getPieceType() const { return pawn; }
}
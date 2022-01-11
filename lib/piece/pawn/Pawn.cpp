#include "Pawn.h"

namespace chess
{
    Pawn::Pawn(Point _position, color _pieceColor, Board& _boardRef)
    {
        position = _position;
        pieceColor = _pieceColor;
        boardRef = &_boardRef;
    }

    piece Pawn::getPieceType() const { return pawn; }

    char Pawn::toChar() const {return (pieceColor == color::white? 'p' : 'P');}

    vector<Move> Pawn::getMoves() const
    {
        vector<Move> ans;
        // "forward" move direction, adjusted by color
        Point forward = pieceColor==color::white ? up : down;

        // Forward move
        Point advance = position + forward;
        if (advance.inBoard())
        {   // Add forward move if destination is empty
            if (boardRef->getPieceAt(advance) == nullptr) ans.push_back(Move(position,advance));
        }

        //TODO
        return ans;
    }
}
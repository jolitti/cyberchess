#include "Move.h"

namespace chess
{
    Move::Move(Point _start, Point _destination):
    start {_start}, destination {_destination} 
    {
        // Preprocessing of the string representation
        repr = start.toString() + " " + destination.toString();
    }

    string Move::toString() const { return repr; }

    void Move::execute(Board& b)
    {
        if (hasBeenExecuted) throw std::logic_error("Move has already been executed");
        hasBeenExecuted = true;

        Piece* movingPiece = b.getPieceAt(start);
        if (movingPiece == nullptr) throw std::logic_error("No piece at starting location");
        if (b.getPieceAt(destination) != nullptr) throw std::logic_error("Unexpected piece at destination");

        b.removePieceAt(start);
        b.setPieceAt(destination, *movingPiece);
        
        b.addMove(*this);
    }
    
}
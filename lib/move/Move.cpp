#include "Move.h"

namespace chess
{
    Move::Move(Point _start, Point _destination, color _movingColor):
    start {_start}, destination {_destination}, movingColor {_movingColor} {}

    string Move::toString() const { return start.toString() + " " + destination.toString(); }

    void Move::execute(Board& b)
    {

        if (hasBeenExecuted) throw std::logic_error("Move has already been executed");
        hasBeenExecuted = true;

        piece movingPiece = b.getPieceAt(start);
        auto[type,col] = movingPiece;
        if (type == none ) throw std::logic_error("No piece at starting location");
        auto[destType, _] = b.getPieceAt(destination);
        if (destType != none) throw std::logic_error("Unexpected piece at destination");

        b.removePieceAt(start);
        b.setPieceAt(destination, movingPiece);
    }

    Point Move::getStart() const { return start; }
    Point Move::getDestination() const { return destination; }
    color Move::getColor() const { return movingColor; }
    
}
// Marco Giacomin 2016269

#include "Move.h"

namespace chess
{
    Move::Move(): start{Point()},destination{Point()},hasBeenExecuted{false} {}

    Move::Move(Point _start, Point _destination, color _movingColor):
    start {_start}, destination {_destination}, movingColor {_movingColor}, hasBeenExecuted{false} {}

    Point Move::getStart() const { return start; }
    Point Move::getDestination() const { return destination; }
    color Move::getColor() const { return movingColor; }


    string Move::toString() const { return start.toString() + " " + destination.toString(); }

    void Move::validityCheck(Board& b)
    {
        if (hasBeenExecuted) throw std::logic_error("Move has already been executed");
        hasBeenExecuted = true;

        piece movingPiece = b.getPieceAt(start);
        auto[type,col] = movingPiece;
        if (type == none ) throw std::logic_error("No piece at starting location");
    }

    void Move::execute(Board& b)
    {
        //std::cout << "Executing normal move\n";
        validityCheck(b);
        auto[destType, _] = b.getPieceAt(destination);
        if (destType != none) throw std::logic_error("Unexpected piece at destination");

        piece movingPiece = b.getPieceAt(start);
        b.removePieceAt(start);
        b.setPieceAt(destination, movingPiece);
    }

    Move* Move::clone() const
    {
        Move newMove = Move(*this);
        return &newMove;
    }
}

ostream& operator<<(ostream& o, const chess::Move& m)
    {
        o<<m.toString();
        return o;
    }
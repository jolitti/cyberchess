#include "Move.h"

namespace chess
{
    Move::Move(Piece& _toMove, Point _destination):
    toMove {_toMove}, destination {_destination} 
    {
        // Preprocessing of the string representation
        repr = toMove.getPos().toString() + " " + destination.toString();
    }

    string Move::toString() const { return repr; }
    
}
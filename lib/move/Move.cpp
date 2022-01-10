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
    
}
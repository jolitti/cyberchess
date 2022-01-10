#ifndef MOVE_H
#define MOVE_H

#include "../Chess.h"

namespace chess
{
    // Simple move from one Point to the other. Assumed to be legal
    class Move
    {
    protected:
        // The piece that has to be moved as a result of this operation
        Piece& toMove;
        Point destination;

        // Flag to be set to true after move execution
        bool hasBeenExecuted;
        // String representation to be computed at creation
        string repr;
        
    public:
        Move(Piece& _toMove, Point _destination);
        
        // Changes the position of the referenced piece in its referenced board
        // Exepts if the move has already happened
        virtual void execute();

        // Creates a parallel board (via deep copy) to examine the consequences of the move
        // without actually performing it
        virtual Board branch() const;

        // String representation from source to destination (e.g "A1 B2")
        virtual string toString() const;
    };
}

#endif
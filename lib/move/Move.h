#ifndef MOVE_H
#define MOVE_H

#include "../board/Board.h"

namespace chess
{
    // Simple move from one Point to the other. Assumed to be legal
    class Move
    {
    protected:
        Point start;
        Point destination;
        color movingColor;

        // Flag to be set to true after move execution
        bool hasBeenExecuted;
        // String representation to be computed at creation
        // note: precomputation not necessary anymore
        // string repr;
        
    public:
        //Move(Piece& _toMove, Point _destination);
        Move (Point _start, Point _destination, color movingColor);

        // Return starting point of this move
        Point getStart() const;
        // Return ending point of this move
        Point getDestination() const;
        // Return color of moving piece
        color getColor() const;
        
        // Changes the position of the referenced piece in its referenced board
        // Exepts if the move has already happened
        virtual void execute(Board& b);

        // Creates a parallel board (via deep copy) to examine the consequences of the move
        // without actually performing it
        // DO NOT IMPLEMENT YET
        //virtual Board branch(Board& b) const;

        // String representation from source to destination (e.g "A1 B2")
        virtual string toString() const;

        // TODO
        //virtual ~Move();
    };
}

ostream& operator<<(ostream& o, const chess::Move& m);

#endif /* MOVE_H */

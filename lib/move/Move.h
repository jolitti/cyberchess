// Marco Giacomin 2016269

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
        // Undesired, but causes an error in derived classes if removed
        Move();

        //Move(Piece& _toMove, Point _destination);
        Move (Point _start, Point _destination, color movingColor);

        // Return starting point of this move
        Point getStart() const;
        // Return ending point of this move
        Point getDestination() const;
        // Return color of moving piece
        color getColor() const;

        // Throw specific exceptions if validity is not respected
        void validityCheck(Board& b);
        
        // Changes the position of the referenced piece in its referenced board
        // Exepts if the move has already happened
        virtual void execute(Board& b);

        // Creates a parallel board (via deep copy) to examine the consequences of the move
        // without actually performing it
        // DO NOT IMPLEMENT YET
        //virtual Board branch(Board& b) const;

        // String representation from source to destination (e.g "A1 B2")
        virtual string toString() const;

        // Provide a pointer to a new copy of this object (derived-friendly)
        virtual Move* clone() const;
        virtual ~Move() = default;
    };
}

ostream& operator<<(ostream& o, const chess::Move& m);

#include "capture/Capture.h"
#include "enpassant/EnPassant.h"
#include "promotion/Promotion.h"

#endif /* MOVE_H */

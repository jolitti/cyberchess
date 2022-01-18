#ifndef HISTORY_H
#define HISTORY_H

#include "../move/Move.h"
#include "../move/capture/Capture.h"

namespace chess
{
    // timeline of moves on a chess board
    class History
    {
    private:
        vector<unique_ptr<Move>> moves;
        Board& board;

    public:
        History(Board& b);

        ~History() = default;

        // Return reference to internal Board object
        Board& getBoardRef();

        // Return color of the player that has to move
        color movingColor() const;

        // Returns true if point p does not appear in sources or destinations in the list
        bool hasMoved(const Point& p) const;

        // Used to verify that the last move taken was the pawn at this position
        // using its first move option to double step (false if not or if it's not a pawn)
        bool hasPawnJustDoubleStepped(const Point& p) const;

        // Executes move and pushes it onto the moves vector
        void addMove(unique_ptr<Move> m);

    };
}

#endif /* HISTORY_H */

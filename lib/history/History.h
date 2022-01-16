#ifndef HISTORY_H
#define HISTORY_H

#include "../Chess.h"
#include "../move/Move.h"

namespace chess
{
    // timeline of moves on a chess board
    class History
    {
    private:
        vector<Move*> moves;
        Board& board;

    public:
        History(Board& b);

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
        void addMove(Move* m);
    };
}

#endif /* HISTORY_H */

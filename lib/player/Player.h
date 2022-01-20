// Marco Giacomin 2016269

#ifndef PLAYER_H
#define PLAYER_H

#include "../move/Move.h"

namespace chess
{
    class Player
    {
    public:
        virtual unique_ptr<Move> chooseMove(vector<unique_ptr<Move>> possibleMoves) = delete;
    };
}

#endif /* PLAYER_H */

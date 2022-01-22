// Marco Giacomin 2016269

#ifndef PLAYER_H
#define PLAYER_H

#include "../move/Move.h"

namespace chess
{
    class Player
    {
    public:
        // Extract one of the possible moves between the list of provided ones
        // (criterion depends on implementation)
        virtual unique_ptr<Move> chooseMove(vector<unique_ptr<Move>> possibleMoves, const string& boardRepr) = delete;
    };
}


#include "bot/Bot.h"
#include "human/Human.h"

#endif /* PLAYER_H */

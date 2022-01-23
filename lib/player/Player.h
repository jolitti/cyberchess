// Marco Giacomin 2016269

#ifndef PLAYER_H
#define PLAYER_H

#include "../history/History.h"

namespace chess
{
    class Player
    {
    public:
        // Extract one of the possible moves between the list of provided ones
        // (criterion depends on implementation)
        virtual unique_ptr<Move> chooseMove(vector<unique_ptr<Move>> possibleMoves, const History& historyRef) = 0;
    };
}

#include "bot/Bot.h"
#include "human/Human.h"

#endif /* PLAYER_H */

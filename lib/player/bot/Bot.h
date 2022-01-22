// Marco Giacomin 2016269

#ifndef BOT_H
#define BOT_H

#include "../Player.h"

namespace chess
{
    class Bot : public Player
    {
    public:
        unique_ptr<Move> chooseMove(vector<unique_ptr<Move>> possibleMoves, const string& boardRepr) override;
    };
}

#endif /* BOT_H */

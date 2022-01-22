#include "Bot.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


namespace chess
{
    unique_ptr<Move> Bot::chooseMove(vector<unique_ptr<Move>> possibleMoves, const string& boardRepr)
    {
        int randIndex = rand()%possibleMoves.size();
        //return std::move(possibleMoves.at(randIndex));
        /*Move* moveClone = possibleMoves.at(randIndex).get()->clone();
        auto newUniquePtr = unique_ptr<Move> {moveClone};
        moveClone = nullptr;
        return newUniquePtr;*/

        return std::move(possibleMoves.at(randIndex));
    }
}
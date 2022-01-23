//Diana Plosnita 2018526

#ifndef HUMAN_H
#define HUMAN_H

#include <string>

#include "../Player.h"
using namespace std;

namespace chess
{
    class Human : public Player
    {
    private:
        //Checks if the move's format is valid (e.g. "B1 C4" correct, "B1C4" incorrect)  
        bool check_format(const string& s_move) const;
        
        //Checks for the special command "XX XX"
        bool check_special(const string& s_move) const;

    public:
        virtual unique_ptr<Move> chooseMove(vector<unique_ptr<Move>> possibleMoves, const History& historyRef) override;

    };
}

#endif /* HUMAN_H*/

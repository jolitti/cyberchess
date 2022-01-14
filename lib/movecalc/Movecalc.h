#ifndef MOVECALC_H
#define MOVECALC_H

// Collections of functions to calculate all legal moves from a chessboard

#include "../Chess.h"
namespace chess
{
    vector<unique_ptr<Move>> getMoves(Board& b, History& h);
}
#endif /* MOVECALC_H */

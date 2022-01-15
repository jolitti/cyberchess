#ifndef MOVECALC_H
#define MOVECALC_H

// Collections of functions to calculate all legal moves from a chessboard

#include "../Chess.h"
#include "../history/History.h"

namespace chess
{
    // Given a board state and its past moves, get all legal moves
    vector<Move*> getLegalMoves(Board& b, History& h);
}
#endif /* MOVECALC_H */

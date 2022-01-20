#include <iostream>
#include "lib/movecalc/Movecalc.h"

using std::cout;
using namespace chess;

int main()
{
    std::cout<<"Initializing board"<<"\n";

    // I cannot for the life of me explain why we need to bring Move and its derived classes in scope
    // like this to prevent an undefined reference error
    Move m = Move(down,down*2,color::black);
    Capture c = Capture(down,down*2,color::black);
    EnPassant e = EnPassant(down,down,color::white);
    // NOTE: insert (above) the other derived Move classes as they get written

    Promotion p = Promotion(down,down,color::white);

    Board b = Board();
    History h = History(b);
    
    /* h.addMove(std::move(getLegalMoves(h).at(0)));
    h.addMove(std::move(getLegalMoves(h).at(1))); */
    auto moves = getLegalMoves(h);
    cout << moves.size() << " moves available:" << '\n';
    for (auto &m : moves)
    {
        cout << *m.get() << '\n';
    }
}
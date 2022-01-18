#include <iostream>
#include "lib/movecalc/Movecalc.h"
#include "lib/Move/enPassant/enPassant.h"

using std::cout;
using namespace chess;

int main()
{
    std::cout<<"Initializing board"<<"\n";

    // I cannot for the life of me explain why we need to bring Move and its derived classes in scope
    // like this to prevent an undefined reference error
    Move m = Move(down,down*2,color::black);
    Capture c = Capture(down,down*2,color::black);
    // NOTE: insert (above) the other derived Move classes as they get written

    Board b = Board(chess::CAPTURE_TEST);
    History h = History(b);
    
    /*auto m2 = std::make_unique<Move>(Move(down*6,down*5,color::white));

    cout << "Move created " << m2->getStart() << "\n";

    h.addMove(std::move(m2));

    cout << "Move complete" << "\n"; */

    auto e = std::make_unique<EnPassant>(EnPassant(down*6,down*5,color::white));

    auto moves = chess::getLegalMoves(h);
    cout << moves.size() << " moves available:" << '\n';
    for (auto &m : moves)
    {
        cout << *m.get() << '\n';
    }
}
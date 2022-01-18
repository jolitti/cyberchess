#include <iostream>
#include "lib/Chess.h"
#include "lib/move/Move.h"
#include "lib/history/History.h"
#include "lib/movecalc/Movecalc.h"

using std::cout, chess::color, chess::piece, chess::Point, chess::Board;
using chess::Move, chess::History;

int main()
{
    std::cout<<"Initializing board"<<"\n";

    Board b = Board();
    History h = History(b);
    
    auto m = std::make_unique<Move>(Move(down*6,down*5,color::white));

    cout << "Move created " << m.get() << "\n";

    h.addMove(std::move(m));

    cout << "Move complete" << "\n";

    auto moves = chess::getLegalMoves(h);
    cout << b << '\n';
    cout << moves.size() << '\n';
}
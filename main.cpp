#include <iostream>
#include "lib/Chess.h"
#include "lib/movecalc/Movecalc.h"

using std::cout, chess::color, chess::piece, chess::Point, chess::Board;
using chess::Move, chess::History;

int main()
{
    std::cout<<"Initializing board"<<"\n";

    Board b = Board();
    History h = History(b);
    Move m = Move(up,down,color::white);

    //cout<<b.toString()<<'\n';

    //cout<<b.getPieces(color::white).size()<<'\n';
}
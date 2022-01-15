#include <iostream>
#include "lib/Chess.h"
//#include "lib/movecalc/Movecalc.h"

#include "lib/board/Board.h"

using std::cout, chess::color, chess::piece, chess::Point, chess::Board;
//using chess::Move;

int main()
{
    std::cout<<"Initializing board"<<"\n";

    Board b = Board();

    cout<<b.toString()<<'\n';
}
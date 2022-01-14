#include <iostream>
#include "lib/Chess.h"
#include "lib/point/Point.h"
using std::cout, chess::color, chess::piece, chess::Point;
using chess::Move;

int main()
{
    /* piece p  {chess::pieceType::pawn,color::black};
    Point pp {1,1};
    cout<<"Hello, world!\n";
    cout<<pp<<"\n";

    auto[x,y] = pp.toPair();
    cout << x << " " << y <<"\n"; */

    auto m = std::make_unique<Move>(Move{Point{1,1},Point{1,2},color::white});
    cout<<m.get()<<"\n";
}
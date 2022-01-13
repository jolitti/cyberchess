#include <iostream>
#include "lib/Chess.h"
#include "lib/point/Point.h"
using std::cout, chess::color, chess::piece, chess::Point;

int main()
{
    piece p = piece::pawn;
    Point pp {1,1};
    cout<<"Hello, world!\n";
    cout<<pp<<"\n";

    auto[x,y] = pp.toPair();
    cout << x << " " << y <<"\n";
}
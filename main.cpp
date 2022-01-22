#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lib/movecalc/Movecalc.h"
#include "lib/player/Player.h"

using std::cout;
using namespace chess;

int main()
{
    srand (time(NULL));

    std::cout<<"Initializing board"<<"\n";

    // I cannot for the life of me explain why we need to bring Move and its derived classes in scope
    // like this to prevent an undefined reference error
    Move m = Move(down,down*2,color::black);
    Capture c = Capture(down,down*2,color::black);
    EnPassant e = EnPassant(down,down,color::white);
    Promotion p = Promotion(down,down,color::white);
    // NOTE: insert (above) the other derived Move classes as they get written

    

    Board b = Board(PROMOTION_TEST);
    History h = History(b);
    Bot bot = Bot();
    Player* player1 = &bot;

    cout<<b<<'\n';

    auto moves = getLegalMoves(h);
    h.addMove(player1->chooseMove(std::move(moves),b.toString()));

    cout<<b<<'\n';
}
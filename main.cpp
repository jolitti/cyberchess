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
    const unsigned int MAX_ITER = 50;
    srand (time(NULL));

    std::cout<<"Initializing board"<<"\n";

    // I cannot for the life of me explain why we need to bring Move and its derived classes in scope
    // like this to prevent an undefined reference error
    Move m = Move(down,down*2,color::black);
    Capture c = Capture(down,down*2,color::black);
    EnPassant e = EnPassant(down,down,color::white);
    Promotion p = Promotion(down,down,color::white);
    // NOTE: insert (above) the other derived Move classes as they get written

    

    Board b = Board();
    History h = History(b);
    Player* player1 = new Bot(); // white player
    Player* player2 = new Bot(); // black player

    cout<<b<<'\n';

    unsigned int iter = 0;
    while (true)
    {
        auto possibleMoves = getLegalMoves(h);
        if (possibleMoves.size() <= 0 || iter>MAX_ITER) break;

        color movingColor = h.movingColor();
        Player* movingPlayer = movingColor==white?player1:player2;

        try
        {
            h.addMove(movingPlayer->chooseMove(std::move(possibleMoves),h));
        }
        catch (const std::exception& e)
        {
            cout<<"Exception caught!\n";
            cout<<e.what()<<'\n';
        }
        iter++;
    }

    cout<<b<<'\n';
}
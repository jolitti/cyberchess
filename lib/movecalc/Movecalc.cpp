#include "Movecalc.h"

namespace chess
{
    vector<unique_ptr<Move>> getLegalMoves(History& h)
    {
        vector<unique_ptr<Move>> ans {};

        color movingColor = h.movingColor();
        Board& b = h.getBoardRef();
        
        auto movingPieces = b.getPieces(movingColor);

        for (pair<piece,Point> p : movingPieces)
        {
            auto [piecePair, position] = p;
            auto [type, color] = piecePair;
            switch (type)
            {
                case pawn:
                    {
                        Point stepDirection = (movingColor==black)?down:up;
                        if (b.getPieceAt(position + stepDirection).first == none) 
                        {
                            // Standard pawn step
                            ans.push_back(std::make_unique<Move>(position,position+stepDirection,movingColor));
                            if (b.getPieceAt(position + stepDirection*2).first == none && !h.hasMoved(position))
                            {   
                                // Pawn double step (as the pawn's first move)
                                ans.push_back(std::make_unique<Move>(position,position+stepDirection*2,movingColor));
                            }
                        }
                    }
            }
        }

        return ans;
    }
}
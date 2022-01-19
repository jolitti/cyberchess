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
                        if ((position+stepDirection).inBoard() &&b.getPieceAt(position + stepDirection).first == none) 
                        {
                            // Standard pawn step
                            ans.push_back(std::make_unique<Move>(position,position+stepDirection,movingColor));
                            if (b.getPieceAt(position + stepDirection*2).first == none && !h.hasMoved(position)
                                && (position + stepDirection*2).inBoard())
                            {   
                                // Pawn double step (as the pawn's first move)
                                ans.push_back(std::make_unique<Move>(position,position+stepDirection*2,movingColor));
                            }
                        }
                        // Capture
                        for (Point sideDir : {left,right})
                        {
                            Point capPos = position + stepDirection + sideDir;
                            if (capPos.inBoard() 
                                && b.getPieceAt(capPos).first!=none 
                                && b.getPieceAt(capPos).second==oppositeColor(movingColor))
                            {
                                ans.push_back(std::make_unique<Move>(Capture(position,capPos,movingColor)));
                            }

                            // calculate En Passant
                            if (capPos.inBoard()
                                && b.getPieceAt(capPos).first == none
                                && b.getPieceAt(capPos-stepDirection).first == pawn
                                && b.getPieceAt(capPos-stepDirection).second == oppositeColor(movingColor)
                                && h.hasPawnJustDoubleStepped(capPos-stepDirection))
                            {
                                ans.push_back(std::make_unique<Move>(EnPassant(position,capPos,movingColor)));
                            }
                        }
                    }
            }
        }

        return ans;
    }
}
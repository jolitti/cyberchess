#include "Movecalc.h"


namespace chess
{
    // Insert appropriate moves for pieces that move on straight lines
    // (bishop, rook, queen)
    void iterateOverLine(Point startPos, Point dir, color movingColor, vector<unique_ptr<Move>>& ans, Board& b)
    {
        int i = 1;
        while (true)
        {
            Point newPos = startPos + dir*i;
            if (!newPos.inBoard()) break;
            auto [type,col] = b.getPieceAt(newPos);
            if (type == none) ans.push_back(std::make_unique<Move>(Move(startPos,newPos,movingColor)));
            else
            {
                if (col == oppositeColor(movingColor))
                    ans.push_back(std::make_unique<Move>(Capture(startPos,newPos,movingColor)));
                break;
            }
        }
    }

    // Add according move (for knight and king)
    void singleStepMove(Point startPos, Point dir, color movingColor, vector<unique_ptr<Move>>& ans, Board& b)
    {
        Point newPos = startPos + dir;
        if (newPos.inBoard())
        {
            auto [type,col] = b.getPieceAt(newPos);
            if (type==none) ans.push_back(std::make_unique<Move>(Move(startPos,newPos,movingColor)));
            else if (col == oppositeColor(movingColor))
                ans.push_back(std::make_unique<Move>(Capture(startPos,newPos,movingColor)));
        }
    }

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
                        break;
                    }

                case knight:
                {
                    for (Point dir : KNIGHT_MOVES) 
                    {
                        //std::cout<<"Testing move "<<(position+dir)<<'\n';
                        singleStepMove(position,dir,movingColor,ans,b);
                    }
                    break;
                }

                case bishop:
                {
                    for (Point dir : DIAGONALS) iterateOverLine(position,dir,movingColor,ans,b);
                    break;
                }

                case rook:
                {
                    for (Point dir : ORTHOGONALS) iterateOverLine(position,dir,movingColor,ans,b);
                    break;
                }

                case queen:
                {
                    for (Point dir : ORTHOGONALS) iterateOverLine(position,dir,movingColor, ans,b);
                    for (Point dir : DIAGONALS) iterateOverLine(position,dir,movingColor,ans,b);
                    break;
                }

                case king:
                {
                    for (Point dir : ORTHOGONALS) singleStepMove(position,dir,movingColor, ans,b);
                    for (Point dir : DIAGONALS) singleStepMove(position,dir,movingColor,ans,b);
                    break;
                }
            }
        }

        return ans;
    }
}
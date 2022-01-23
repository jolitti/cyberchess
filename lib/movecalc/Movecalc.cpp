//Marco Giacomin 2016269

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
            //std::cout<<newPos<<'\n';
            if (!newPos.inBoard()) break;
            auto [type,col] = b.getPieceAt(newPos);
            if (type == none) ans.push_back(std::make_unique<Move>(Move(startPos,newPos,movingColor)));
            else
            {
                if (col == oppositeColor(movingColor))
                    ans.push_back(std::make_unique<Capture>(Capture(startPos,newPos,movingColor)));
                break;
            }
            i++;
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
                ans.push_back(std::make_unique<Capture>(Capture(startPos,newPos,movingColor)));
        }
    }

    vector<unique_ptr<Move>> getLegalMoves(History& h)
    {
        vector<unique_ptr<Move>> ans {};

        color movingColor = h.movingColor();
        Board& b = h.getBoardRef();
        
        auto movingPieces = b.getPieces(movingColor);

        // If king has been eaten, return empty vector to signal end of game to main()
        bool hasKing = false;
        for (auto[piecePair,pos] : movingPieces) if (piecePair.first == king) hasKing = true;
        if (!hasKing) return ans;

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
                            Point newPos = position + stepDirection;
                            int newY = newPos.toPair().second;
                            // Standard pawn step
                            if (newY!=0 && newY != BOARD_SIZE-1) ans.push_back(std::make_unique<Move>(position,position+stepDirection,movingColor));
                            else
                            {
                                //std::cout<<"Adding promotions" << '\n';
                                for (pieceType type : POSSIBLE_PROMOTIONS)
                                    ans.push_back(std::make_unique<Promotion>(
                                        Promotion(position,newPos,movingColor,type)
                                    ));
                                //std::cout << "Finished adding promotions \n";
                            }

                            Point doubleStep = position + stepDirection*2;
                            if (doubleStep.inBoard()
                                &&b.getPieceAt(doubleStep).first == none && !h.hasMoved(position))
                            {   
                                // Pawn double step (as the pawn's first move)
                                ans.push_back(std::make_unique<Move>(position,doubleStep,movingColor));
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
                                ans.push_back(std::make_unique<Capture>(Capture(position,capPos,movingColor)));
                            }

                            // calculate En Passant
                            if (capPos.inBoard()
                                && b.getPieceAt(capPos).first == none
                                && b.getPieceAt(capPos-stepDirection).first == pawn
                                && b.getPieceAt(capPos-stepDirection).second == oppositeColor(movingColor)
                                && h.hasPawnJustDoubleStepped(capPos-stepDirection))
                            {
                                ans.push_back(std::make_unique<EnPassant>(EnPassant(position,capPos,movingColor)));
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
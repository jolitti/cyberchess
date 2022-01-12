#include <iostream>
#include "Board.h"
#include "Piece.h" 

#include <vector>

using namespace std;

namespace chess
{
	
	Board::Board()
	: pieces(BOARD_SIZE, vector<Piece*>(BOARD_SIZE, nullptr))
	, moves()
	{

		//white pieces
		//Pawn(Point _position, color _pieceColor, Board& _boardRef);
		pieces[0][0] = new Rook(Point(0,0), white, this); 
		pieces[0][7] = new Rook(Point(0,7), white, this);
		pieces[0][1] = new Knight(Point(0,1), white, this);
		pieces[0][6] = new Knight(Point(0,6), white, this);
		pieces[0][2] = new Bishop(Point(0,2), white, this);
		pieces[0][5] = new Bishop(Point(0,5), white, this);
		pieces[0][3] = new Queen(Point(0,3), white, this);
		pieces[0][4] = new King(Point(0,4), white, this);
		for(int i=0; i<BOARD_SIZE, i++)
			pieces[1][i] = new Pawn(Point(1,i), white, this);


		//black pieces
		pieces[7][0] = new Rook(Point(7,0), black, this); 
		pieces[7][7] = new Rook(Point(7,7), black, this);
		pieces[7][1] = new Knight(Point(7,1), black, this);
		pieces[7][6] = new Knight(Point(7,6), black, this);
		pieces[7][2] = new Bishop(Point(7,2), black, this);
		pieces[7][5] = new Bishop(Point(7,5), black, this);
		pieces[7][3] = new Queen(Point(7,3), black, this);
		pieces[7][4] = new King(Point(7,4), black, this);
		for(int i=0; i<BOARD_SIZE; i++)
			pieces[6][i] = new Pawn(Point(6,i), black, this);

		toMove = white;
	} 

	Piece* getPieceFromSeed(piece p, Point pos, color c)
	{
		switch(p)
		{
			case pawn:
				return new Pawn(pos, c, this);
			case rook:
				return new Rook(pos, c, this);
			case knight:
				return new Knight(pos, c, this);
			case bishop:
				return new Bishop(pos, c, this);
			case queen:
				return new Queen(pos, c, this);
			case king:
				return new King(pos, c, this);
			default:
				return nullptr;
		}
	}

	Board::Board(const string& seed)
	{
		for(unsigned int i=0; i<seed.size(); i++)
		{
			piece p = LETTER_TO_PIECE_IT[s];
			unsigned int x = i / BOARD_SIZE;
			unsigned int y = i % BOARD_SIZE;
			Point point(x,y);
			pieces[x][y] = getPieceFromSeed(point, pos, toMove);
		}
	}


    Piece* Board::getPieceAt(const Point& position) const
    {
    	auto[x, y] = position.toPair();
    	return pieces[x][y];
    }

    Piece* Board::setPieceAt(const Point& position, Piece& newValue)
    {
    	auto[x, y] = position.toPair();
    	Pieces* oldPiece = pieces[x][y];
		pieces[x][y] = &newValue; //corretto assegnare per reference? 

		return oldPiece;
    }

    Piece* Board::removePieceAt(const Point& position) //dove verrebbe usata? Cioè non basta setPieceAt()?
    {
		auto[x, y] = position.toPair();
    	Pieces* oldPiece = pieces[x][y];
		pieces[x][y] = nullptr;

		return oldPiece;    
    }

    color Board::getMovingColor() const
    {
    	return toMove;
    }

    //ci servirebbe un metodo getPiece() dentro Move per ottenere la Piece 
    //(per ora non vedo nessun altro modo di accedere alla piece tramite Move)
    vector<Move> Board::getMoves() const 
    {
    	vector<Move> colorMoves;
    	for(auto move : moves)
    	{
    		if((moves.getPiece()).getColor() == toMove)
    			colorMoves.push_back(move);
    	}
    	return colorMoves;
    }

    const vector<Move>& Board::getMoveHistory() const
    {
    	return moves;
    }


    void Board::addMove(Move m)
    {
    	moves.push_back(m);
    	toMove = oppositeColor(toMove);
    }


	void Board::save_move(Move move)
	{
		moves.push_back(move);
	}

	// Le operazioni che dovremo fare sulle mosse saranno tutte iterazioni sulla lista, quindi consiglio
	// di sostituire queste funzioni con qualcosa che restituisca const vector<vector<Piece*>>&
	
	//basta un riferimento immutabile perchè l'unico cambiamento che subirà la lista di mosse sarà push_back

	unsigned int Board::get_history_size() const
	{
		return moves.size();
	}

	Move Board::get_move(unsigned int index) const
	{
		return move[index];
	}


	string Board::toString() const
	{
		string s = ""; 
		for (unsigned int i=0; i<BOARD_SIZE; i++)
		{
			for (unsigned int j=0; j<BOARD_SIZE; j++)
			{
				if (pieces[i][j] != nullptr)
					s = s + (pieces[i][j])->toChar();
				else s = s + " ";
			}
			s = s + "\n";
		}
	}

	ostream& operator<< (ostream& o, const Board& b)
    { 
        o << b.toString();
        return o;
    }

}
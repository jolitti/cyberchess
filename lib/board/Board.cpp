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
		toMove = white;
		return Board(INITIAL_STATE);
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
			string s = seed[i];
			piece p = LETTER_TO_PIECE_IT[s];
			unsigned int x = i / BOARD_SIZE;
			unsigned int y = i % BOARD_SIZE;
			Point point(x,y);
			color c;
			if (s.isupper())
				c = black;
			else c = white;
			pieces[x][y] = getPieceFromSeed(point, pos, c);
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
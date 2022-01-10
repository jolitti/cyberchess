#include <iostream>
#include "Board.h"
#include "Piece.h"

using namespace std;

namespace chess
{
	Board::Board()
	: pieces(BOARD_SIZE, vector<Piece*>(BOARD_SIZE, nullptr))
	, moves()
	{

		//white pieces
		pieces[0][0] = new Piece('t');
		pieces[0][7] = new Piece('t');
		pieces[0][1] = new Piece('c');
		pieces[0][6] = new Piece('c');
		pieces[0][2] = new Piece('a');
		pieces[0][5] = new Piece('a');
		pieces[0][3] = new Piece('d');
		pieces[0][4] = new Piece('r');
		for(int i=0; i<8; i++)
			pieces[1][i] = new Piece('p');

		//black pieces
		pieces[7][0] = new Piece('T');
		pieces[7][7] = new Piece('T');
		pieces[7][1] = new Piece('C');
		pieces[7][6] = new Piece('C');
		pieces[7][2] = new Piece('A');
		pieces[7][5] = new Piece('A');
		pieces[7][3] = new Piece('D');
		pieces[7][4] = new Piece('R');
		for(int i=0; i<8; i++)
			pieces[6][i] = new Piece('P');



		//Pawn(Point _position, color _pieceColor, Board& _boardRef)
		pieces[0][0] = new Tower(Point(0,0), color::white, this); // ?
	} 

	void Board::print() const
	{
		for (unsigned int i=0; i<BOARD_SIZE; i++)
		{
			for (unsigned int j=0; j<BOARD_SIZE; j++)
			{
				cout << (pieces[i][j])->toChar();
			}
			cout << endl;
		}

	}

	void Board::save_move(Move move)
	{
		moves.push_back(move);
	}

	unsigned int Board::get_history_size() const
	{
		return moves.size();
	}

	Move Board::get_move(unsigned int index) const
	{
		return move[index];
	}

	bool Board::set_move(Point start_pos, Point end_pos)
	{
		pair<int, int> start = start_pos.toPair();
		pair<int, int> end = end_pos.toPair();
		if ((pieces[start.first][start.second] == nullptr) && (pieces[end.first][end.second] != nullptr))
			return false;

		Piece p = pieces[start.first][start.second];
		pieces[end.first][end.second] == p;
		pieces[start.first][start.second] == nullptr;
		return true;
	}
}
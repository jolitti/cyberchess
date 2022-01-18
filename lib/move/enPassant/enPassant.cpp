#include "EnPassant.h"
#include "math.h"

namespace chess
{
	EnPassant::EnPassant(Point _start, Point _destination, color movingColor)
	: Move(_start, _destination, movingColor) 
	{}

	void EnPassat::execute_eat(Board& b)
	{
		validityCheck(b);

		auto [dest_x, dest_y] = destination.toPair();
		auto [start_x, start_y] = start.toPair();

		int y_eat = (movingColor == white) ? (y_eat - 1) : (y_eat + 1);

		int x_distance = abs(dest_x - start_x);
		Point p_eat (dest_x, y_eat); 
		auto [eat_type, eat_color] = b.getPieceAt(p_eat);
		if ((eat_color == oppositeColor(movingColor)) && (eat_type == pawn) && (x_distance == 1))
		{
			piece movingPiece = b.getPieceAt(start);
			b.removePieceAt(start);
			b.removePieceAt(p_eat);
			b.setPieceAt(destination, movingPiece);
		}
		else throw std::logic_error("not possible to do an en passant");
	}

	
}
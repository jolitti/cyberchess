//Diana Plosnita 2018526

#include "EnPassant.h"
#include "math.h"

namespace chess
{
	EnPassant::EnPassant(Point _start, Point _destination, color movingColor)
	: Move(_start, _destination, movingColor) 
	{}

	void EnPassant::execute(Board& b)
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
			piece moving_piece = b.getPieceAt(start);
			b.removePieceAt(start);
			b.removePieceAt(p_eat);
			b.setPieceAt(destination, moving_piece);
		}
		else throw std::logic_error("not possible to do an en passant");
	}

	Move* EnPassant::clone() const
    {
        EnPassant newEnPassant = EnPassant(*this);
        return &newEnPassant;
    }

	
}
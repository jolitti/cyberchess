//Diana Plosnita 2018526

#include "Promotion.h"

#include <ctype.h>
#include <string>

namespace chess
{

	Promotion::Promotion(Point _start, Point _destination, color movingColor, pieceType type)
	: Move(_start, _destination, movingColor)
	, final_form(type)
	{}
	
	void Promotion::execute(Board& b) 
	{
		validityCheck(b);
		auto [piece_type, _] = b.getPieceAt(start);
		if (piece_type != pawn)
			throw std::logic_error("only pawns can be promoted");

		piece moving_piece = b.getPieceAt(start);
		moving_piece.first = final_form;
		b.removePieceAt(start);
		b.setPieceAt(destination, moving_piece);
	}	

	string Promotion::toString() const
	{
		char promoted = PIECE_TO_LETTER_IT.at(final_form);

		if (movingColor == black)
			promoted = toupper(promoted);

		return (start.toString() + " " + destination.toString() + " " + promoted);
	}

}
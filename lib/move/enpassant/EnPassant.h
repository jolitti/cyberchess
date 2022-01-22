//Diana Plosnita 2018526

#ifndef ENPASSANT_H
#define ENPASSANT_H

#include "../Move.h"

namespace chess
{
	
	class EnPassant : public Move
	{

	public:

		EnPassant(Point _start, Point _destination, color movingColor);

		~EnPassant() = default;

        // Move and capture corresponding pieces on Board b, performing en passant
		void execute(Board& b) override;

		Move* clone() const override;

	};

}


#endif /* ENPASSANT_H */

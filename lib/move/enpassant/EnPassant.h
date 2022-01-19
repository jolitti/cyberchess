#ifndef ENPASSANT_H
#define ENPASSANT_H

#include "../Move.h"

namespace chess
{
	
	class EnPassant : public Move
	{
	private:

	public:

		EnPassant(Point _start, Point _destination, color movingColor);

		~EnPassant() = default;

		void execute(Board& b) override;

	};

}


#endif /* ENPASSANT_H */

//Diana Plosnita 2018526

#ifndef PROMOTION_H
#define PROMOTION_H

#include "../Move.h"

namespace chess
{

	class Promotion : public Move
	{
	private:
		pieceType final_form;

	public:

		Promotion(Point _start, Point _destination, color movingColor, pieceType type);

		~Promotion() = default;

		//move and capture if needed, promoting the moving piece to its final form
		void execute(Board& b) override;

		//String representation from source to destination and promotion type(e.g "A1 B2 D")
		string toString() const override;

		Move* clone() const override;
	};

}

#endif /* PROMOTION_H */
//Diana Plosnita 2018526

#include "History.h"
#include "math.h"

namespace chess
{
	History::History(Board& b)
	: moves{}, board {b} {}

	Board& History::getBoardRef() const
	{ 
		return board; 
	}

	color History::movingColor() const
	{
		if (moves.size() <= 0) return color::white;
		return oppositeColor((moves.back().get()->getColor()));
	}

	bool History::hasMoved(const Point& p) const
	{
		for(auto& m : moves)
		{
			if (m->getDestination() == p) //iterando sul vettore moves, se trova registrato p come start, vuol dire che è stato mosso(?)
				return true;
		}
		return false;
	}

	bool History::hasPawnJustDoubleStepped(const Point& p) const
	{
		if ((board.getPieceAt(p)).first != pieceType::pawn) return false;

		Move& lastMove = *moves.back(); 
		int diffY = abs(lastMove.getStart().toPair().second - lastMove.getDestination().toPair().second);
		return diffY == 2;
	}


	void History::addMove(unique_ptr<Move> m)
	{
		std::cout << "Executing move "<< m->toString() << "\n";
		m->execute(board);
		moves.push_back(std::move(m));
	}

	Move History::getLastMove() const
	{
		return *moves[moves.size()-1]; 
	}
}
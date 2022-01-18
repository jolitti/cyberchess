#include "History.h"

namespace chess
{
	History::History(Board& b)
	: moves{}, board {b} {}

	Board& History::getBoardRef() { return board; }

	color History::movingColor() const
	{
		if (moves.size() <= 0) return color::white;
		return oppositeColor((moves.back()->getColor()));
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

	///devo aggiungere riferimento alla Board altrimenti non riesco sapere che pedina si trova nella posizione p 
	//bisogna anche che la classe Move abbia dei metodi che mi permettono di conoscere il start e il destination delle pedine 
	//ovvero quello che qua ho scritto get_start() e get_destination()
	bool History::hasPawnJustDoubleStepped(const Point& p) const
	{
		
		if ((board.getPieceAt(p)).first != pieceType::pawn) return false;
		// Basta controllare l'ultima mossa
		/* Point start;
		for(int i=moves.size(); i>=0; i--)
		{
			if (moves[i]->get_destination() == p)
			{
				start = moves[i]->get_start();
				break;
			}
		}
		auto xy_p = p.toPair();
		auto xy_start = start.toPair();
		if (xy_p.first - xy_start.first == 2)
			return true;
		else return false; 	 */	

		Move& lastMove = *moves.back(); 
		int diffY = abs(lastMove.getStart().toPair().second - lastMove.getDestination().toPair().second);
		return diffY == 2;
	}


	void History::addMove(unique_ptr<Move> m)
	{
		std::cout << "Executing move "<<m->toString()<<"\n";
		m->execute(board);
		moves.push_back(std::move(m));
	}
}
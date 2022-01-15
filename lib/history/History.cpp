namespace chess
{
	History::History()
	: moves()
	{

	}

	bool History::hasMoved(const Point& p) const
	{
		for(auto m : moves)
		{
			if (m->get_start() == p) //iterando sul vettore moves, se trova registrato p come start, vuol dire che è stato mosso(?)
				return true;
		}
		return false;
	}

	///devo aggiungere riferimento alla Board altrimenti non riesco sapere che pedina si trova nella posizione p 
	//bisogna anche che la classe Move abbia dei metodi che mi permettono di conoscere il start e il destination delle pedine 
	//ovvero quello che qua ho scritto get_start() e get_destination()
	bool History::hasPawnJustDoubleStepped(const Point& p, const Board& b) const
	{
		
		if ((b.getPieceAt(p)).first != pieceType::pawn) return false;
		Point start;
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
		else return false; 		
	}


	void History::addMove(Move* m)
	{
		moves.push_back(m);
	}
}
//Diana Plosnita 2018526

#include "Human.h"

#include <ctype.h>
#include <iostream>


namespace chess
{
	bool Human::check_format(const string& s_move) const
	{
		if( isalpha(s_move[0]) && 
			isdigit(s_move[1]) &&
			s_move[2] == ' '   &&
			isalpha(s_move[3]) &&
			isdigit(s_move[4])	)
			return true;

		return false;
	}

	bool Human::check_special(const string& s_move) const
	{
		string s_emtpy = "";
		if((s_empty + s_move[0] + s_move[1]) == "XX"  && 
			s_move[2] == ' ' &&
			(s_empty + s_move[3] + s_move[4]) == "XX")
			return true;

		return false;
	}

	unique_ptr<Move> Human::chooseMove(vector<unique_ptr<Move>> possibleMoves, const History& historyRef)
	{

		bool flag = false;
		unique_ptr<Move> p = nullptr;

		while(flag == false)
		{
			string s_move;
			cin >> s_move;

			if (check_special(s_move))
				cout << historyRef.getBoardRef().toVerboseString(); 
			else
			{
				if(!check_format(s_move))
					cout << "invalid move format";
				else
				{
					for(p : possibleMoves)
					{
						if(p->toString() == s_move)
						{
							flag = true;
							break;
						}
					}
					if(flag == false)
						cout << "illegal move, try again";
				}
			}
		}

		return std::move(p);
	}
}
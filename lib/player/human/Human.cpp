//Diana Plosnita 2018526

#include "Human.h"

#include <ctype.h>
#include <iostream>
#include <algorithm>


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
		string empty_s = "";
		if((empty_s + s_move[0] + s_move[1]) == "XX"  && 
			s_move[2] == ' ' &&
			(empty_s + s_move[3] + s_move[4]) == "XX")
			return true;

		return false;
	}

	unique_ptr<Move> Human::chooseMove(vector<unique_ptr<Move>> possibleMoves, const History& historyRef)
	{

		bool flag = false;
		unsigned int i = 0;

		while(flag == false)
		{
			cout << "Insert move ";
			string s_move;
			getline(cin, s_move);
			transform(s_move.begin(), s_move.end(), s_move.begin(), ::toupper);

			if (check_special(s_move))
				cout << historyRef.getBoardRef().toString() << "\n"; 
			else
			{
				if(!check_format(s_move))
					cout << "invalid move format";
				else
				{
					for(i=0; i<possibleMoves.size(); i++)
					{
						string pos_move = possibleMoves[i]->toString();
						transform(pos_move.begin(), pos_move.end(), pos_move.begin(), ::toupper);
						if(pos_move == s_move)

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

		return std::move(possibleMoves[i]);
		return std::move(p);
	}
}
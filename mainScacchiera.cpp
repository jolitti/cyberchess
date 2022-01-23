//Diana Plosnita 2018526

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>

#include "lib/movecalc/Movecalc.h"
#include "lib/player/Player.h"

using namespace std;
using namespace chess;

int main(int argc, char* argv[])
{
	if(strcmp(argv[1], "cc") == 0)
	{
		const unsigned int MAX_ITER = 50;
		srand (time(NULL));

		Board b = Board();
		History h = History(b);

		Player* player1 = new Bot(); // white player
		Player* player2 = new Bot(); // black player

		cout << "Initial state of the board: " << endl;
		cout << b << endl;

		unsigned int iter = 0;
		while (true)
		{
			auto possibleMoves = getLegalMoves(h);
			if (possibleMoves.size() <= 0 || iter > MAX_ITER) break;

			color movingColor = h.movingColor();
			Player* movingPlayer = movingColor == white ? player1 : player2;

			cout << "color " << (movingColor == 0 ? "black" : "white") << ": ";
			try
			{
				h.addMove(movingPlayer->chooseMove(std::move(possibleMoves), h));
			}
			catch (const std::exception& e)
			{
				cout << "Exception caught!\n";
				cout << e.what() << '\n';
			}
			iter++;
		}

		cout << "Final state of the board: " << endl;
		cout << b << endl;
	}
	else if(strcmp(argv[1], "pc") == 0)
	{
		srand (time(NULL));

		Board b = Board();
		History h = History(b);

		unsigned int random_player = rand() % 2; //generate random {0, 1}
		Player* player1; 
		Player* player2;

		if (random_player == 0)
		{
			player1 = new Bot(); // white player
			player2 = new Human(); // black player
		}
		else 
		{
			player1 = new Human(); // white player
			player2 = new Bot(); // black player
		}


		cout << "Initial state of the board: " << endl;
		cout << b << endl;

		unsigned int iter = 0;
		while (true)
		{
			auto possibleMoves = getLegalMoves(h);
			if (possibleMoves.size() <= 0) break;

			color movingColor = h.movingColor();
			Player* movingPlayer = movingColor == white ? player1 : player2;

			cout << "color " << (movingColor == 0 ? "black" : "white") << ": ";
			try
			{
				h.addMove(movingPlayer->chooseMove(std::move(possibleMoves), h));
			}
			catch (const std::exception& e)
			{
				cout << "Exception caught!\n";
				cout << e.what() << '\n';
			}
			iter++;
		}

		cout << "Final state of the board: " << endl;
		cout << b << endl;
	}

	else 
	{
		cout << "unknown configuration, possible options {pc, cc}" << "\n";
		return 1;
	}

}
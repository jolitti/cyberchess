#include <string>
using std::string;

namespace chess
{

    // Letters for the x coordinates on the chessboard
    const string LETTERS = "ABCDEFGH";
    // Number of cells on a side of the board
    const int BOARD_SIZE = 8;
    // Standard representation of a position outside the board (e.g. Z9)
    const string INVALID_POS = "INVALID";


    // String representation of the initial board state
    const string INITIAL_STATE =
    "TCADRACT\n"
    "PPPPPPPP\n"
    "        \n"
    "        \n"
    "        \n"
    "        \n"
    "pppppppp\n"
    "tcadract\n";

    const string EMPTY_BOARD =
    "        \n"
    "        \n"
    "        \n"
    "        \n"
    "        \n"
    "        \n"
    "        \n"
    "        \n";

    // Representation of a board with only two pawns
    const string TWO_PAWNS =
    "        \n"
    "    P   \n"
    "        \n"
    "        \n"
    "        \n"
    "        \n"
    "   p    \n"
    "        \n";

}
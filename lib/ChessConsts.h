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
}
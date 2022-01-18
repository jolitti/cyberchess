#include "Capture.h"

namespace chess
{
    Capture::Capture(Point _start, Point _destination, color _movingColor)
    {
        start = _start;
        destination = _destination;
        movingColor = _movingColor;
    }

    void Capture::execute(Board& b)
    {
        validityCheck(b);

        piece movingPiece = b.getPieceAt(start);
        b.removePieceAt(start);
        b.setPieceAt(destination, movingPiece);
    }
}
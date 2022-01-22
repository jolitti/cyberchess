// Marco Giacomin 2016269

#ifndef CAPTURE_H
#define CAPTURE_H

#include "../Move.h"

namespace chess
{
    class Capture : public Move
    {
    public:
        Capture(Point _start, Point _destination, color _movingColor);

        // Move and capture corresponding pieces on Board b
        void execute(Board& b) override;

        Capture* clone() const;
        ~Capture() = default;
    };
}

#endif /* CAPTURE_H */

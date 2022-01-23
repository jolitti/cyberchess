//Marco Giacomin 2016269

#ifndef POINT_H
#define POINT_H

#include "../ChessConsts.h"

#include <iostream>
#include <string>
using std::ostream, std::pair, std::string;

namespace chess
{
    // Class representing an immutable point on a chessboard
    class Point
    {
    private:
        int x;
        int y;
    
    public:
        Point() = default;

        Point(int _x, int _y);

        Point operator+ (const Point& p) const;
        Point operator- (const Point& p) const;
        Point operator* (const int i) const;

        bool operator== (const Point& p) const;

        // Is this point inside a standard chess board?
        bool inBoard() const;

        // String representation of this position (e.g "A1")
        string toString() const;

        // Conversion to int,int pair for unpacking
        pair<int,int> toPair() const;

        friend ostream& operator<< (ostream& o, const Point& p);
    };
}

// Standard directions
const chess::Point up {0,-1};
const chess::Point down {0,1};
const chess::Point left {-1,0};
const chess::Point right {1,0};

#endif
#include "Point.h"

namespace chess
{
    Point::Point(int _x, int _y):x{_x},y{_y} {}

    Point Point::operator+(const Point& p) const { return Point(x+p.x,y+p.y); }

    Point Point::operator-(const Point& p) const { return Point(x-p.x,y-p.y); }

    Point Point::operator*(const int i) const { return Point(x*i,y*i); }

    bool Point::operator==(const Point& p) const { return x==p.x && y == p.y; }

    bool Point::inBoard() const 
    {
        return x>=0 && x<BOARD_SIZE
            && y>=0 && y<BOARD_SIZE;
    }

    string Point::toString() const
    {
        if (!inBoard()) return INVALID_POS;
        else return LETTERS.at(x) + std::to_string(y+1);
    }

    ostream& operator<< (ostream& o, const Point& p)
    { 
        o << p.toString();
        return o;
    }
}

std::size_t std::hash<chess::Point>::operator() (const chess::Point& p)
{
    return std::hash<string>()(p.toString());
}
//Marco Giacomin 2016269

#include "Board.h"
#include <algorithm>

namespace chess
{
    Board::Board(const string& seed)
    {   
        //std::cout<<"Initializing board"<<"\n";

        // seed string without newlines
        string compactSeed = seed;
        compactSeed.erase(std::remove(compactSeed.begin(),compactSeed.end(),'\n'),compactSeed.end());
        //std::cout<<compactSeed<< " "<<compactSeed.length() << '\n';


        // 2d vector initialization
        pieces = vector<vector<piece>>(BOARD_SIZE);
        for (int i = 0;i<BOARD_SIZE;i++) pieces[i] = vector<piece>(8,piece {pieceType::none, color::white});

        auto seedIterator = compactSeed.begin();

        forEachPosition([&](const Point& p)
        {
            char c = *seedIterator;
            seedIterator++;
            //std::cout<<"Iter content: "<<LETTER_TO_PIECE_IT.at(c)<<'\n';

            setPieceAt(p, piece{LETTER_TO_PIECE_IT.at(c),colorOf(c)});
        });
    }

    Board::Board() : Board(INITIAL_STATE)
    {
        //std::cout<<"Initializing default board\n";
    }

    string Board::toString() const
    {
        string ans = "";
        unsigned int i = 0;
        forEachPiece([&](const piece& p)
        {
            if (i>=BOARD_SIZE)
            {
                ans += "\n";
                i = 0;
            }
            ans += pieceToLetterIt(p);
            i++;
        });

        return ans;
    }


    template <typename Function>
    void Board::forEachPiece(Function f) const
    {
        for (vector<piece> row : pieces)
        {
            for (piece p : row) f(p);
        }
    }

    template <typename Function>
    void Board::forEachPosition(Function f)
    {
        for (int j = 0; j<BOARD_SIZE; j++)
        {
            for (int i = 0; i<BOARD_SIZE; i++) f(Point(i,j));
        }
    }

    template <typename Function>
    void Board::forEachPositionConst(Function f) const
    {
        for (int j = 0; j<BOARD_SIZE; j++)
        {
            for (int i = 0; i<BOARD_SIZE; i++) f(Point(i,j));
        }
    }

    vector<pair<piece,Point>> Board::getPieces() const
    {
        vector<pair<piece,Point>> ans {};
        
        forEachPositionConst([&](Point pt){
            piece p = getPieceAt(pt);
            if (p.first != none) ans.push_back(pair<piece,Point>{p,pt});
        });

        return ans;
    }

    vector<pair<piece,Point>> Board::getPieces(color c) const
    {
        vector<pair<piece,Point>> ans {};

        forEachPositionConst([&](Point pt){
            piece p = getPieceAt(pt);
            if (p.first != none && p.second == c) ans.push_back(pair<piece,Point>{p,pt});
        });

        return ans;
    }

    piece Board::getPieceAt(const Point& position) const
    {
        auto[x,y] = position.toPair();
        return pieces[y][x];
    }

    piece Board::setPieceAt(const Point& position, piece newValue)
    {
        piece oldVal = getPieceAt(position);
        auto[x,y] = position.toPair();
        pieces[y][x] = newValue;
        return oldVal;
    }

    piece Board::removePieceAt(const Point& position)
    {
        piece oldVal = getPieceAt(position);
        auto[x,y] = position.toPair();
        pieces[y][x] = piece{none,white};
        return oldVal;
    }

    char pieceToLetterIt(const piece& p)
    {
        if (p.first == none) return ' ';
        char ans = PIECE_TO_LETTER_IT.at(p.first);
        if (p.second == color::black) ans = toupper(ans);
        return ans;
    }
}

ostream& operator<< (ostream& o, const chess::Board& b)
{
    o << b.toString() ;
    return o;
}
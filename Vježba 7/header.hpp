#include <iostream>
#include <cmath>

struct Point
{
public:
    double x,y;
    Point(double x,double y);
    ~Point();
};

class Board
{
public:
    int a,b;
    char border = 'o';
    int** matrix;
    int xb,yb;
    char symbol;
    void draw_char(Point& p,char ch);
    void draw_up_line(Point& p,char ch);
    void draw_line(Point& p,Point& p1,char ch);
    void display();
    Board();
    Board(const Board &b);
    Board(int a,int b);
    Board (Board &&b);
    ~Board();
};

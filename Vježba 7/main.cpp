#include "header.hpp"

using namespace std;

Board::Board()//default
{
    cout << "Input rows and columns: " << endl;
    cin >> a >> b;
    matrix = new int*[a];
    cout << "Input the border symbol: " << endl;
    cin >> border;
    for(int i = 0; i < a; i++)
    {
        matrix[i] = new int[b];
    }
}

Board::Board(const Board &board)//copy
{
    a = board.a;
    b = board.b;
    symbol=board.symbol;
    matrix=board.matrix;
}

Board::Board (Board &&board) //move
{
    a = board.a;
    b = board.b;
    symbol = board.symbol;
    matrix = board.matrix;

    board.a = 0;
    board.b = 0;
    board.symbol='\0';
    board.matrix=nullptr;
    delete [] matrix;
}

Board::Board(int z,int p) //constructor s argumentima
{
    a=z;
    b=p;
    matrix = new int*[a];
    for(int i = 0; i < a; i++)
    {
        matrix[i] = new int[b];
    }
}

Board::~Board() //destructor
{
    for(int i = 0; i < a; i++)
        delete [] matrix[i];
    delete [] matrix;
}

void Board::draw_char(Point& p,char ch) //char on coordinates
{
    symbol = ch;
    xb = p.x;
    yb = p.y;
    matrix[xb][yb] = 1;
}

void Board::draw_up_line(Point& p,char ch)  //vertical line
{
    symbol = ch;
    xb = p.x;
    yb = p.y;
    for(int i = 1; i < a; i++)
    {
        for(int j = 1; j < b; j++)
        {
            if(xb >= i)
                matrix[i][yb] = 1;
        }
    }
}

void Board::draw_line(Point& p,Point& p1,char ch) // connecting line
{
    symbol = ch;
    xb = p.x;
    yb = p.y;
    int xc = p1.x;
    int yc = p1.y;
    int temp = 0;
    if(xb > xc)
    {
        temp = xb;
        xb = xc;
        xc = temp;
        temp = 0;
    }
    if(yb > yc)
    {
        temp = yb;
        yb = yc;
        yc = temp;
        temp = 0;
    }
    for(int i = xb; i < xc; i++)
    {
        for(int j = yb; j < yc-1; j++)
        {
            matrix[i][j] = 1;
            i++;
        }
    }
}

void Board::display()
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if(matrix[i][j] == 1)
            {
                cout << symbol;
            }
            else if ((i == 0 || i == a-1) || (j == 0 || j == b-1))
            {
                cout << border;
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

Point::Point(double ar1,double ar2)
{
    x = round(ar1);
    y = round(ar2);
}

Point::~Point() {}

int main()
{
    //Board b1;
    //b1.display();
    Board b(10, 10);
    Board b2(b.a,b.b);
    Point p1(3,2), p2(7, 7);
    b2.draw_char(p1,'x');
    b2.draw_up_line(p2,'x');
    b2.draw_line(p1,p2,'x');
    b2.display();
    Board b4 = b2;
    b4.display();
    Board b3 = std::move(b2);
    b3.display();
    return 0;
}

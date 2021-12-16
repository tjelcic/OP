#include <iostream>

using namespace std;

class Timer
{
    int h,m;
    double s;
public:
    int get_h();
    int get_m();
    double get_s();
    void set_h(int hours);
    void set_m(int minutes);
    void set_s(double seconds);
    Timer();
    Timer(int hours, int minutes, double seconds);
    ~Timer();
    Timer& operator+=(Timer& t);
    Timer& operator-=(const Timer& t);
    Timer& operator/=(int n);
    friend ostream& operator<<(ostream& out, const Timer& t);
    operator double() const;
    friend bool operator<(const Timer& a, const Timer& b);
};

class Penalty
{
    int penalty;
public:
    Penalty(int p);
    void operator()(Timer& t);
};

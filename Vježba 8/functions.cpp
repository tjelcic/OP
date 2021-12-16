#include "header.hpp"

int Timer::get_h()
{
    return h;
}
int Timer::get_m()
{
    return m;
}
double Timer::get_s()
{
    return s;
}
void Timer::set_h(int hours)
{
    h = hours;
}
void Timer::set_m(int minutes)
{
    m = minutes;
}
void Timer::set_s(double seconds)
{
    s = seconds;
}

Timer::Timer()
{
    h = 0;
    m = 0;
    s = 0;
}

Timer::Timer(int hours, int minutes, double seconds)
{
    h = hours;
    m = minutes;
    s = seconds;
}

Timer::~Timer() {};

Timer& Timer::operator+=(Timer& t)
{
    double time = (h * 3600) + (m * 60) + s;
    double time_end = (t.h * 3600) + (t.m * 60) + t.s;
    time += time_end;
    h = time / 3600;
    m = (time / 60) - h*60;
    s = time - m * 60 - h * 3600;
    return *this;
}

Timer& Timer::operator-=(const Timer& t)
{
    double time = h * 3600 + m * 60 + s;
    double time_end = t.h * 3600 + t.m * 60 + t.s;
    time -= time_end;
    h = time / 3600;
    m = (time / 60) - h * 60;
    s = time - m * 60 - h * 3600;
    return *this;
}

Timer& Timer::operator/=(int n)
{
    double time = ((h * 3600) + (m * 60) + s) / n;
    h = time / 3600;
    m = (time / 60) - h * 60;
    s = time - m * 60 - h * 3600;
    return *this;
}

ostream& operator<<(ostream& out, const Timer& t)
{
    return out << t.h << ":" << t.m << ":" << t.s;
}

Timer::operator double() const
{
    double time = h * 3600 + m * 60 + s;
    return time;
}

bool operator<(const Timer& a, const Timer& b)
{
    double time_a = a.h * 3600 + a.m * 60 + a.s;
    double time_b = b.h * 3600 + b.m * 60 + b.s;
    return time_a < time_b;
}

Penalty::Penalty(int p)
{
    penalty = p;
}

void Penalty::operator()(Timer& t)
{
    double time = t.get_h() * 3600 + t.get_m() * 60 + t.get_s();
    time += penalty;
    t.set_h(time / 3600);
    t.set_m((time / 60) - t.get_h() * 60);
    t.set_s(time - t.get_m() * 60 - t.get_h() * 3600);
}

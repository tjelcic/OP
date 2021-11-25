#include <iostream>
#include <time.h>
#include <math.h>
#include <random>

using namespace std;

class Point
{
public:
    double x, y, z;
    void set_value(const double x, const double y, const double z)
    {
        this->x = 0, this->y = 0, this->z = 0;
        if (x!=0 || y!=0 || z!=0)
            this->x = x, this->y = y, this->z = z;
    }
    void set_random(int min, int max)
    {
        this->x = min + rand() % (max - min + 1);
        this->y = min + rand() % (max - min + 1);
        this->z = min + rand() % (max - min + 1);
    }
    void get_value(Point t, double &x, double &y, double &z)
    {
        x = t.x;
        y = t.y;
        z = t.z;
    }
    double twod_distance(Point t, Point t2)
    {
        double distance=sqrt(pow((t.x-t2.x),2)+pow((t.y-t2.y),2));
        return distance;
    }
    double threed_distance(Point t, Point t2)
    {
        double distance=sqrt(pow((t2.x-t.x),2)+pow((t2.y-t.y),2)+pow((t2.z-t.z),2));
        return distance;
    }
};

class Weapon
{
public:
    const int n_bullets = 40;
    int cur_n_bullets = n_bullets;
    void reload()
    {
        this->cur_n_bullets = this->n_bullets;
    }
    Point shoot()
    {
        Point shot;
        this->cur_n_bullets--;
        shot.set_random(1,360);
        return shot;
    }
};

class Target
{
public:
    Point ll;
    Point ur;
    bool hit(Point shot)
    {
        return ((shot.x > ll.x && shot.y > ll.y) && (shot.x < ur.x && shot.y < ur.y));
    }
};

int main()
{
    srand(time(NULL));
    int n;
    cout << "Input number of targets: " << endl;
    cin >> n;
    Target *T=new Target[n];
    Weapon w;

    default_random_engine gen;
    uniform_real_distribution<double> dis(1,360);

    int hits=0;

    for (int i = 0; i < n; i++)
    {
        double x1=dis(gen),y1=dis(gen),z1=dis(gen);
        double x2=dis(gen),y2=dis(gen),z2=dis(gen);
        T[i].ll.set_value(x1,y1,z1);
        T[i].ur.set_value(x2,y2,z2);

        while(w.cur_n_bullets != 0)
        {
            w.shoot();
            if (T[i].hit(w.shoot()) == true)
                hits++;
        }
    }
    cout << "Targets were hit " << hits << " times." << endl;
    w.reload();
    delete[] T;
    return 0;
}

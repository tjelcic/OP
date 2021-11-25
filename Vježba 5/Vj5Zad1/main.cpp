#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

class Point
{
private:
    double x, y, z;
public:
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

int main()
{
    srand (time(NULL));
    Point p,p1;
    int min=1;
    int max=50;
    double x,y,z;
    p.set_random(min,max);
    p.get_value(p,x,y,z);
    cout << x << " " << y << " " << z << endl;
    p1.set_random(min,max);
    p1.get_value(p1,x,y,z);
    cout << x << " " << y << " " << z << endl;
    cout << "2d distance between points: " << p.twod_distance(p,p1) << endl;
    cout << "3d distance between points: " << p1.threed_distance(p,p1);
}

#include <iostream>

using namespace std;

typedef struct
{
    int x,y;
}Point;

typedef struct
{
    int r;
    Point S;
}Circle;

typedef struct
{
    Point a,b;
}Rectangle;

int findOverlap(const Rectangle (&arr)[4], const Circle &c, int n)
{
    Point delta;
    int cnt=0;

    for(int i=0;i<n;i++)
    {
        delta.x=c.S.x - ((c.S.x < arr[i].a.x) ? arr[i].a.x : (c.S.x > arr[i].b.x) ? arr[i].b.x : c.S.x);
        delta.y=c.S.y - ((c.S.y < arr[i].a.y) ? arr[i].a.y : (c.S.x > arr[i].b.y) ? arr[i].b.y : c.S.y);

        if((delta.x * delta.x + delta.y * delta.y) <= c.r * c.r)
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    Rectangle arr[]={{{-1,-1},{-2,-2}},{{3,3},{4,4}},{{3,5},{5,8}},{{7,1},{8,3}}};
    Circle c={3,{3,3}};
    int n=sizeof (arr)/sizeof(arr[0]);
    cout << findOverlap(arr,c,n) << " rectangles overlap with the circle" << endl;
    return 0;
}

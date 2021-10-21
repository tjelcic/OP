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
    Point Delta;
    int cnt=0;

    for(int i=0;i<n;i++)
    {
        Delta.x=c.S.x - max(arr[i].a.x, min(c.S.x, arr[i].b.x));
        Delta.y=c.S.y - max(arr[i].a.y, min(c.S.y, arr[i].b.y));

        if((Delta.x * Delta.x + Delta.y * Delta.y) <= c.r * c.r)
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
    cout<<findOverlap(arr,c,n)<<" rectangles overlap with the circle"<<endl;
    return 0;
}

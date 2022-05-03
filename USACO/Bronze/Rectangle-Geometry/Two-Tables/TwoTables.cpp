#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
struct rect
{
    lli x1, y1 , x2 , y2;
};
lli area(rect rect1)
{
    return (rect1.x2 - rect1.x1)*(rect1.y2 - rect1.y1 );
}
lli dist(rect rect1, rect rect2)
{
    lli x1 = max(rect1.x1,rect2.x1 );
    lli y1 = max(rect1.y1, rect2.y1);
    lli x2 = min(rect1.x2, rect2.x2);
    lli y2 = min(rect1.y2, rect2.y2);
    if(x1 > x2 || y1 > y2)
    {
        return 0;
    }
    return -1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        lli W, H;
        cin>>W>>H;
        rect table;
        cin>>table.x1>>table.y1>>table.x2>>table.y2;
        lli w, h;
        cin>>w>>h;
        lli tw = table.x2 - table.x1;
        lli th = table.y2 - table.y1;
        if(tw + w > W && th + h > H)
        {
            cout<<-1<<'\n';
            continue;
        }
        else if (tw + w > W)
        {
            //   need to adjust along height;
            lli dist = LONG_MAX;
            dist = min(dist, max(0ll, table.y2 + h - H));
            dist = min(dist, max(0ll, h - table.y1));
            cout<<dist<<'\n';
        }
        else if (th + h > H)
        {
            lli dist = LONG_MAX;
            dist = min(dist, max(0ll, table.x2 + w - W));
            dist = min(dist, max(0ll, w - table.x1));
            cout<<dist<<'\n';
        }
        else 
        {
            lli dist = LONG_MAX;
            dist = min(dist, max(0ll, table.y2 + h - H));
            dist = min(dist, max(0ll, h - table.y1));
            dist = min(dist, max(0ll, table.x2 + w - W));
            dist = min(dist, max(0ll, w - table.x1));
            cout<<dist<<'\n';
        }

    }
}
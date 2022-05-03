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
lli area(rect rect1, rect rect2)
{
    lli x1 = max(rect1.x1,rect2.x1 );
    lli y1 = max(rect1.y1, rect2.y1);
    lli x2 = min(rect1.x2, rect2.x2);
    lli y2 = min(rect1.y2, rect2.y2);
    if(x1 > x2 || y1 > y2)
    {
        return 0;
    }
    return (x2 - x1)*(y2 - y1);
}
lli area(rect rect1, rect rect2 , rect rect3)
{
    lli x1 = max(rect1.x1,rect2.x1 );
    lli y1 = max(rect1.y1, rect2.y1);
    lli x2 = min(rect1.x2, rect2.x2);
    lli y2 = min(rect1.y2, rect2.y2);
    if(x1 > x2 || y1 > y2)
    {
        return 0;
    }
    return area({x1, y1, x2, y2}, rect3);
}
int main()
{
    rect white, black1, black2;
    cin>>white.x1>>white.y1>>white.x2>>white.y2;
    cin>>black1.x1 >> black1.y1 >> black1.x2 >> black1.y2;
    cin>>black2.x1 >> black2.y1 >> black2.x2 >> black2.y2;
    lli are = area(white);
    lli x1 = area(white, black1);
    lli x2 = area(white, black2);
    are -= x1;
    are -= x2;
    are += area(white, black1, black2);
    if(are != 0)
    {
        cout<<"YES\n";
    }
    else {
        cout<<"NO\n";
    }
}
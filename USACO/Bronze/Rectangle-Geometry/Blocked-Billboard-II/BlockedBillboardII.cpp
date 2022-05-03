#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
struct rect
{
    lli x1, y1, x2, y2;
};
bool contains(lli x1, lli x2, lli x3)
{
    return (x1 <= x3) &&( x2 >= x3);
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
bool happens(lli x1, lli x2, lli X1, lli X2)
{
    return (X1 < x1 && x1 < X2) && (X1 < x2 && x2 < X2);
}
lli area(rect rect1)
{
    return (rect1.x2 - rect1.x1)*(rect1.y2 - rect1.y1 );
}
int main()
{
    ifstream mycin;
    mycin.open("billboard.in");
    ofstream mycout;
    mycout.open("billboard.out");
    rect lawn, bilboard;
    mycin>>lawn.x1>>lawn.y1>>lawn.x2>>lawn.y2;
    mycin>>bilboard.x1>>bilboard.y1>>bilboard.x2>>bilboard.y2;
    if((contains(bilboard.x1, bilboard.x2, lawn.x1) && contains(bilboard.x1, bilboard.x2, lawn.x2)))
    {
        // doing thing 1
        if(happens(bilboard.y1, bilboard.y2, lawn.y1, lawn.y2))
        {
            mycout<<area(lawn)<<'\n';
        }
        else
            mycout<<(area(lawn) - area(lawn, bilboard))<<'\n';
    }
    else if ((contains(bilboard.y1, bilboard.y2, lawn.y1) && contains(bilboard.y1, bilboard.y2, lawn.y2)))
    {
        // doing thing 2
        if(happens(bilboard.x1, bilboard.x2, lawn.x1, lawn.x2))
        {
            mycout<<area(lawn)<<'\n';
        }
        else
            mycout<<(area(lawn) - area(lawn, bilboard))<<'\n';
    }
    else
    {
        mycout<<area(lawn)<<'\n';
    }
    mycin.close();
    mycout.close();
    return 0;

}
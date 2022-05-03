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
int main()
{
    ifstream mycin;
    mycin.open("billboard.in");
    ofstream mycout;
    mycout.open("billboard.out");
    rect alex, greg, truck;
    mycin>>alex.x1>>alex.y1>>alex.x2>>alex.y2;
    mycin>>greg.x1>>greg.y1>>greg.x2>>greg.y2;
    mycin>>truck.x1>>truck.y1>>truck.x2>>truck.y2;
    lli are = 0;
    are += area(alex);
    are += area(greg);
    // cout<<are<<'\n';
    // are -= 2*area(alex, greg);
    are -= area(alex, truck);
    are -= area(greg, truck);
    // cout<<are<<'\n';
    mycout<<are<<'\n';
    mycin.close();
    mycout.close();
}
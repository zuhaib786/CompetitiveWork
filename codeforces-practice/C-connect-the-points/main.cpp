#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int arr[200005];
struct point{
    int x;
    int y;
};

int main()
{
    point p1, p2 , p3;
    int x[3], y[3];
    cin>>p1.x>>p1.y>>p2.x>>p2.y>>p3.x>>p3.y;
    x[0] = p1.x;
    x[1] = p2.x;
    x[2] = p3.x;
    y[0] = p1.y;
    y[1] = p2.y;
    y[2] = p3.y;
    sort(x, x + 3);
    sort(y, y + 3);
    point median = {x[1], y[1]};
    // p1 to median 2lines
    // p2 to median  2 lines
    /// p3 to median 2 lines
    cout<< 6<<endl;
    cout<<p1.x<<" "<<p1.y<<" "<<p1.x<<" "<<median.y<<endl;
    cout<<p1.x<<" "<<median.y<<" "<<median.x<<" "<<median.y<<endl;
    cout<<p2.x<<" "<<p2.y<<" "<<p2.x<<" "<<median.y<<endl;
    cout<<p2.x<<" "<<median.y<<" "<<median.x<<" "<<median.y<<endl;
    cout<<p3.x<<" "<<p3.y<<" "<<p3.x<<" "<<median.y<<endl;
    cout<<p3.x<<" "<<median.y<<" "<<median.x<<" "<<median.y<<endl;
    return 0;

}
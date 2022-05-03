#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
struct rect
{
    lli x1, y1, x2, y2;
};

int main()
{
    ifstream mycin;
    mycin.open("square.in");
    ofstream mycout;
    mycout.open("square.out");
    rect sq1, sq2;
    mycin>>sq1.x1>>sq1.y1>>sq1.x2>>sq1.y2;
    mycin>>sq2.x1>>sq2.y1>>sq2.x2>>sq2.y2;
    lli x1 = min(sq1.x1, sq2.x1);
    lli y1 = min(sq1.y1, sq2.y1);
    lli x2 = max(sq1.x2, sq2.x2);
    lli y2 = max(sq1.y2, sq2.y2);
    lli length = max(x2 - x1, y2 - y1);
    mycout<<length * length<<'\n';
}
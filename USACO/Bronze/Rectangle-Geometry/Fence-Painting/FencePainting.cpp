#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int main()
{
    ifstream mycin;
    mycin.open("paint.in");
    ofstream mycout;
    mycout.open("paint.out");
    lli a, b, c,d;
    mycin>>a>>b>>c>>d;
    if(b < c || d < a)
    {
        // [a b]   [c  d]
        mycout<< (b - a )+ (d - c)<<'\n';
    }
    else if ((a <= c && c <= b) || (c <= a &&  a <= d))
    {
        // [a   [c   b]   d], [a  [c  d]  b]
        mycout<<(max(b,d ) - min(a, c) )<<'\n';
    }
}
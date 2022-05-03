#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
bool between(lli x, lli y, lli z)
{
    return (x <= z) && (z <= y); 
}
int main()
{
    ifstream mycin;
    mycin.open("lostcow.in");
    ofstream mycout;
    mycout.open("lostcow.out");
    lli x, y;
    mycin>>x>>y;
    lli dist = 0;
    lli mul = 0;
    int curPos = x;
    int startPos = x;
    int turn = 0;
    while(!between(min(curPos, startPos), max(curPos, startPos), y))
    {
        dist += abs(curPos - startPos);
        
        startPos = curPos;
        
        if(turn == 0)
        {
            curPos = x + pow(2, mul);
        }
        else
        {
            curPos = x - pow(2, mul);
        }
        // cout<<startPos << " "<<curPos<<'\n';
        mul++;
        turn ^= 1;
    }
    dist += abs(startPos - y);
    mycout<<dist<<'\n';
    mycin.close();
    mycout.close();

}

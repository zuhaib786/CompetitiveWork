#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int main()
{
    ifstream mycin;
    mycin.open("mixmilk.in");
    ofstream mycout;
    mycout.open("mixmilk.out");
    lli cap[3];
    lli milk[3];
    mycin>>cap[0]>>milk[0];
    mycin>>cap[1]>>milk[1];
    mycin>>cap[2]>>milk[2];
    int turn = 0;
    for(int i = 0; i< 100; i++)
    {
        if(turn == 0)
        {
            if(milk[1] + milk[0] > cap[1])
            {
                milk[0] -= cap[1] - milk[1];
                milk[1] = cap[1];
            }
            else
            {
                milk[1] = milk[0] + milk[1];
                milk[0] = 0;
            }
        }
        else if (turn == 1)
        {
            if(milk[2] + milk[1] > cap[2])
            {
                milk[1] -= cap[2] - milk[2];
                milk[2] = cap[2];
            }
            else
            {
                milk[2] = milk[1] + milk[2];
                milk[1] = 0;
            }
        }
        else
        {
            if(milk[0] + milk[2] > cap[0])
            {
                milk[2] -= cap[0] - milk[0];
                milk[0] = cap[0];
            }
            else
            {
                milk[0] = milk[0] + milk[2];
                milk[2] = 0;
            }
        }
        turn++;
        turn %= 3;
    }
    mycout<<milk[0]<<'\n'<<milk[1]<<'\n'<<milk[2]<<'\n';
    return 0;
}

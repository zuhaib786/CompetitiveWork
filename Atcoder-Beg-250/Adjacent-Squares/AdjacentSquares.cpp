#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int main()
{
    lli H, W;
    lli R, C;
    cin>>H>>W>>R>>C;
    int cnt = 0;
    if( R + 1 <= H)
    {
        cnt++;
    }
    if( R - 1>= 1)
    {
        cnt++;
    }
    if(C + 1 <= W)
        cnt++;
    if( C - 1>= 1)
    {
        cnt++;
    }
    cout<<cnt<<'\n';
}


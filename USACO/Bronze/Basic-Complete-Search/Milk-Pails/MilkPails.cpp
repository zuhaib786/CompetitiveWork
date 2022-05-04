#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
void setIO(string name = "")
{
    if(name.size() ==0)
        return;
    cin.tie(0)->sync_with_stdio(0);
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
int main()
{
    setIO("pails");
    lli x, y, m;
    cin>>x>>y>>m;
    lli maxFill = 0;
    for(int i = 0; i*x <= m; i++)
    {
        for(int j = 0; j*y <= m - i*x; j++)
        {
            maxFill = max( i * x + j * y , maxFill);
        }
    }
    cout<<maxFill<<'\n';
}

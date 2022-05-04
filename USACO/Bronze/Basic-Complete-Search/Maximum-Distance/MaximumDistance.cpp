#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
lli x[5005];
lli y[5005];
int main()
{
    int n;
    cin>>n;
    for(int i = 0; i< n; i++)
    {
        cin>>x[i];
    }
    for(int j = 0; j< n; j++)
    {
        cin>>y[j];
    }
    lli dist = LONG_MIN;
    for(int i = 0; i<n; i++)
    {
        for(int j= i + 1; j< n; j++)
        {
            lli dx = x[i] - x[j];
            dx = dx*dx;
            lli dy = y[i] - y[j];
            dy *= dy;
            dist = max(dist, dx + dy);
        }
    }
    cout<<dist<<'\n';
}

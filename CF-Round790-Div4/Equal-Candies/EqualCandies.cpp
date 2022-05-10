#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
void solve()
{
    int n;
    cin>>n;
    lli sum = 0;
    lli mn = LONG_MAX;
    for(int i = 0; i<n; i++)
    {
        lli k ;
        cin>>k;
        mn = min(k, mn);
        sum += k;
    }
    cout<<(sum - n*mn)<<'\n';
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }   
}

#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
#define FOR(i, n) for(int i = 0; i<n; i++)
#define ff first
const int maxN = 1e5 + 5;
struct query
{
    lli left, right, i;
}Q[maxN];
lli arr[maxN];
lli brr[3*maxN];
lli ps[3*maxN];
int main()
{
    freopen("haybales.in", "r",stdin);
    freopen("haybales.out", "w", stdout);
    int n,q ;
    cin>>n>>q;
    map<lli,lli> m;
    FOR(i, n)
    {
        cin>>arr[i];
        m[arr[i]];
    }
    FOR(i, q)
    {
        cin>>Q[i].left>>Q[i].right;
        m[Q[i].left];
        m[Q[i].right];
        Q[i].i;
    }
    lli cnt = 0;
    for(auto x: m)
    {
        m[x.ff] = cnt;
        cnt++;
    }
    memset(brr, 0, sizeof(brr));
    FOR(i, n)
    {
        brr[m[arr[i]]]++;
    }
    FOR(i , cnt)
    {
        ps[i + 1] = ps[i ] + brr[i]; 
    }
    FOR(i, q)
    {
        lli l = Q[i].left;
        lli r = Q[i].right;
        l = m[l];
        r = m[r];
        cout<<ps[r + 1] - ps[l]<<'\n';
    }
    
}
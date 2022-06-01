#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;


#define ff first
#define ss second
#define FOR(i, n) for(int i= 0; i<n; i++)
#define all(x) begin(x), end(x)

const int maxN = 2e5 + 5;
pii Ldoors[maxN];
pii Rdoors[maxN];
pii Ldist[maxN];
pii Rdist[maxN];
lli manhat(pii x , pii y)
{
    return abs(x.ff - y.ff) + abs(x.ss - y.ss);
}
void solve()
{
    int n;
    cin>>n;
    FOR(i, n - 1)
    {
        cin>>Ldoors[i].ff>>Ldoors[i].ss>>Rdoors[i].ff>>Rdoors[i].ss;
    }
    FOR(i, n - 2)
    {
        // lli x = Ldoors[i].ff;
        // lli y = Ldoors[i].ss;
        lli dist1 = manhat(Ldoors[i], Ldoors[i + 1]);
        lli dist2 = manhat(Ldoors[i], Rdoors[i + 1]);
        lli dist3 = manhat(Rdoors[i], Ldoors[i + 1] );
        lli dist4 = manhat(Rdoors[i], Rdoors[i + 1]);
        Ldist[i] = {dist1, dist2};
        Rdist[i] = {dist3, dist4};
    }


}
int main()
{
    int t;
    // cin>>t;
    t = 1;
    while(t--)
    {
        solve();
    }
}
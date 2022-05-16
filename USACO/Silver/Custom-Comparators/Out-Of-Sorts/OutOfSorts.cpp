#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
using vc = vector<lli>;
#define ff first
#define ss second
#define FOR(i,n,k) for(int i = 0; i<n; i+= k)
const int maxN = 1e5 + 5;
pii arr[maxN];
pii cp[maxN];
void setIO(string name)
{
    cin.tie(0)->sync_with_stdio(0);
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
int main()
{
    setIO("sort");
    int n;
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i].ff;
        arr[i].ss = i;
        cp[i] = arr[i];
    }
    sort(cp, cp + n);
    map<pii, int>m;
    int cnt = 0;
    FOR(i, n, 1)
    {
        m[cp[i]] = cnt;
        cnt++;
    }
    int ans = 0;
    FOR(i, n, 1)
    {
        ans = max(ans, i - m[arr[i]]);
    }
    cout<<ans + 1<<'\n';
    

}
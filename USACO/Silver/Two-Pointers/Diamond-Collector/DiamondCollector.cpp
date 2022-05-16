#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
using vc = vector<lli>;
#define ff first
#define ss second
#define FOR(i, n) for(int i = 0; i<n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0 ; i--)
const int maxN  = 1e5 + 5;
void setIO(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
lli arr[maxN];
lli dp[maxN];
lli rt[maxN];
int main()
{
    setIO("diamond");
    lli n,k;
    cin>>n>>k;
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort(arr , arr + n);
    memset(dp, 0, sizeof(dp));
    int j = 0;
    FOR(i, n)
    {
        while(j < n && arr[j] - arr[i] <= k)
        {
            j++;
        }
        dp[i] = j - i;
    }
    memset(rt, 0, sizeof(rt));
    ROF(i, n)
    {
        rt[i] = max(rt[i + 1], dp[i]);
    }
    lli ans = 0;
    FOR(i, n)
    {
        ans = max(ans, dp[i] + rt[i + dp[i]]);
    }
    cout<<ans<<'\n';


}
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
using vc = vector<lli>;

#define ff first
#define ss second

#define FOR(i, n) for(int i = 0; i<n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0; i--)


void setIO(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
const int maxN = 1e5 + 5;
lli arr[maxN];
int main()
{
    setIO("lemonade");
    int n;
    cin>>n;
    FOR(i, n)
    {
        cin>>arr[i];
    }
    sort(arr, arr + n, greater<lli>());
    lli ans = 0;
    FOR(i, n)
    {
        ans += arr[i]>=i;
    }
    cout<<ans<<'\n';
}
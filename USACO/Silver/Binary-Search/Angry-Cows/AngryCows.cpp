#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
using vc = vector<lli>;

#define ff first
#define ss second
#define FOR(i, n) for(int i = 0; i<n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0; i--)

const int maxN = 2e5 + 5;
lli arr[maxN];
bool Poss(lli mid, lli n, lli k)
{
    int j = 0;
    int ct = 0;
    FOR(i, n)
    {
        if(arr[i] - arr[j] > 2*mid)
        {
            ct++;
            j = i;
        }
    }
    ct++;
    return ct<=k;
}
int main()
{
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    lli n, k;
    cin>>n>>k;
    lli mx = INT_MIN;
    lli mn = INT_MAX;
    FOR(i, n)
    {
        cin>>arr[i];
        mx = max(mx, arr[i]);
        mn = min(mn, arr[i]);
    }
    sort(arr, arr + n);
    lli left = 0;
    lli right = mx - mn;
    lli ans = right;
    while(left <= right)
    {
        lli mid = left + (right - left)/2;
        if(Poss(mid, n, k))
        {
            right = mid-1;
            ans = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout<<ans<<'\n';
}
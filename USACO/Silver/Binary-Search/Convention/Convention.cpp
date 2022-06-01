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
bool Poss(lli mid, lli n, lli c, lli m)
{
    int j = 0;
    lli ct = 0;
    FOR(i, n)
    {
        if(i - j + 1>c || arr[i] - arr[j]>mid)
        {
            ct++;
            j = i;
        }
    }
    ct++;
    return ct<=m;
}
int main()
{
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    lli n, m,c;
    cin>>n>>m>>c;
    FOR(i, n)
    {
        cin>>arr[i];
    }
    sort(arr, arr + n);
    lli left = 0;
    lli right = arr[n - 1];
    lli ans = right;
    while(left <= right)
    {
        lli mid = left + (right - left)/2;
        if(Poss(mid, n , c, m))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout<<ans<<'\n';
}

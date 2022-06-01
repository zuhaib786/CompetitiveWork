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
pii arr[maxN];
bool Poss(lli mid, lli n, lli m)
{
    lli ct  = 0;
    lli lastPos = INT_MIN;
    FOR(i, m)
    {
        if(arr[i].ff - lastPos >=mid)
        {
            // cout<<"Second: "<<(arr[i].ss - arr[i].ff)/mid + 1<<'\n';
            ct += (arr[i].ss - arr[i].ff)/mid + 1;
            lastPos = arr[i].ff + ((arr[i].ss - arr[i].ff)/mid)*mid;
        }
        else
        {
            if(lastPos + mid > arr[i].ss)
            {
                continue;
            }
            else
            {
                // cout<<"First : "<<(arr[i].ss - lastPos - mid)/mid + 1<<'\n';
                ct += (arr[i].ss - lastPos - mid)/mid + 1;
                lastPos = lastPos + mid + ((arr[i].ss - lastPos - mid)/mid)*mid;
            }
        }
    }

    // cout<<mid<<" "<<ct<<'\n';
    return ct >=n;
}
int main()
{
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    lli n, m;
    cin>>n>>m;
    FOR(i, m)
    {
        cin>>arr[i].ff>>arr[i].ss;
    }
    sort(arr, arr + m);
    lli left = 1; 
    lli right = arr[ m - 1].ss - arr[0].ff;
    lli ans = 1;
    // cout<<left<<" "<<right<<'\n';
    while(left <= right)
    {

        lli mid = left + (right - left)/2;
        if(Poss(mid, n, m))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid -1;
        }
    }
    cout<<ans<<'\n';
}
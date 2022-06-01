#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
#define FOR(i, n) for(int i = 0; i< n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0; i--)
#define all(x) begin(x), end(x)
const int maxN = 2e5 + 5;
lli arr[maxN];

bool Poss(lli mid, int n, int k)
{
    lli cur = 0;
    lli ct = 0;
    FOR(i, n)
    {
        if(cur + arr[i] > mid)
        {
            cur = arr[i];
            ct++;
        }
        else
        {
            cur += arr[i];
        }
    }
    ct++;
    return ct <= k;
}

int main()
{
    int n, k;
    cin>>n>>k;
    lli right = 0;
    lli left = 0;
    FOR(i, n)
    {
        cin>>arr[i];
        right += arr[i];
        left = max(left, arr[i]);
    }
    lli ans;
    while(left <= right)
    {
        lli mid = left + (right - left )/2;
        if(Poss(mid, n, k))
        {
            ans = mid;
            right = mid -1 ;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout<<ans<<'\n';

}
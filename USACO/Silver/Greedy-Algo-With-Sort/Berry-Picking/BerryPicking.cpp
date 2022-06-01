#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
#define FOR(i,n ) for(int i = 0; i < n; i++)
const int maxN = 1003;
lli arr[maxN];
lli mod = 1;
bool comp(const int & i1, const int & i2)
{
    return i1 % mod > i2 % mod;
}
int main()
{
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    int n,k;
    cin>>n>>k;
    lli best = 0;
    lli mx = 0;
    FOR(i, n)
    {
        cin>>arr[i];
        mx = max(arr[i], mx);
    }
    FOR(b, mx)
    {
        mod = b + 1;
        lli ct  = 0;
        lli sm = 0;
        FOR(i, n)
        {
            lli j = arr[i];
            lli bc = arr[i]/mod;
            ct += bc;
        }
        if(ct < k/2)
        {
            break;
        }
        else if (ct >= k)
        {
            best = max(best, mod * (k/2));
        }
        else
        {
            sort(arr, arr + n, comp);
            sm = 0;
            sm = mod *(ct - k/2);
            FOR(i, k - ct)
            {
                sm += arr[i]%mod;
            }
            best = max(best, sm);
        }
    }
    cout<<best<<'\n';

    
}
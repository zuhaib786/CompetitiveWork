#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
#define ff first
#define ss second
#define FOR(i, n, k) for(int i = 0; i<n; i+=k)
const int maxN = 2e5 + 5;
lli arr[maxN];
int main()
{
    lli n, t;
    cin>>n>>t;
    FOR(i, n, 1)
    {
        cin>>arr[i];
    }
    lli cur = 0;
    int best = 0;
    int len = 0;
    int j =0;
    FOR(i, n, 1)
    {
        cur += arr[i];
        while(cur > t)
        {
            cur -= arr[j];
            j++;
        }

        assert(cur <= t);
        best = max(best, i - j + 1);
    }
    cout<<best<<'\n';
}
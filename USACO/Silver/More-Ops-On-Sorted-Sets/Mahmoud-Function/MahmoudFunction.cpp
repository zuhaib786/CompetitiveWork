#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using vc = vector<lli>;
using pii = pair<lli, lli>;

#define ff first
#define ss second

#define FOR(i,n) for(int i =0; i<n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0; i--)

const int maxN = 1e5 + 5;
lli arr[maxN];
lli brr[maxN];

int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    FOR(i, n)
    {
        cin>>arr[i];
    }
    FOR(i, m)
    {
        cin>>brr[i];
    }
    // alternate sums of brr->:)
    // from j to n + j for each such possible j
    int stidx = 0;
    int idx = 0;
    set<lli>st;
    lli curSum = 0;
    int j =0;
    FOR(i, n - 1)
    {
        if(idx == 0)
        curSum += brr[i];
        else
        curSum -= brr[i];
        idx ^= 1;
    }
    for(int i = n - 1; i<m; i++)
    {
        if(idx == 0)
        curSum += brr[i];
        else
        curSum -= brr[i];
        idx ^= 1;
        if(stidx == 0)
        {
            st.insert(curSum);
            curSum -= brr[j];
        }
        else
        {
            st.insert(-curSum);
            curSum += brr[j];
        }
        j++;
        stidx ^= 1;
    }
    lli tot = 0;
    idx = 0;
    FOR(i, n)
    {
        if(idx == 0)
        tot += arr[i];
        else 
        tot -= arr[i];
        idx ^=1;
    }
    auto it = st.lower_bound(tot);
    lli ans = 0;
    if(it == st.end())
    {
        it--;
        ans = abs(*it - tot);

    }
    else
    if(it == st.begin())
    {
        ans = abs(*it - tot);
    }
    else
    {
        ans = abs(*it - tot);
        ans = min(ans, abs(*prev(it) - tot));
    }
    cout<<ans<<'\n';
    FOR(i, q)
    {
        lli l, r, x;
        cin>>l>>r>>x;
        if(l%2 == r%2)
        {
            if(l%2)
            {
                tot += x;
            }
            else
            {
                tot -= x;
            }
        }
        it = st.lower_bound(tot);
        lli ans = 0;
        if(it == st.end())
        {
            it--;
            ans = abs(*it - tot);

        }
        else
        if(it == st.begin())
        {
            ans = abs(*it - tot);
        }
        else
        {
            ans = abs(*it - tot);
            ans = min(ans, abs(*prev(it) - tot));
        }
        cout<<ans<<'\n';
    }
    
}
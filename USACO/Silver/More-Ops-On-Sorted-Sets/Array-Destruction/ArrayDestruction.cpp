#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
#define ff first
#define ss second
#define FOR(i,n) for(int i = 0; i<n; i++)
#define ROF(i,n) for(int i = n - 1; i>=0; i--)
using vc = vector<pii>;
const int maxN = 1e3 + 3;
lli arr[2*maxN];
void solve()
{
    int n;
    cin>>n;
    FOR(i,2 * n)
    {
        cin>>arr[i];
    }
    sort(arr, arr + 2*n, greater<lli>());
    multiset<lli>s;
    FOR(i, 2*n)
    {
        s.insert(arr[i]);
    }
    // cout<<s.size()<<'\n';
    bool hogya = false;
    lli x;vc ans;
    FOR(i, 2*n -1)
    {
        // cout<<"Iteration number: "<<i + 1<<'\n';  
        int idx =  i + 1;
        multiset<lli>cp = s;
        cp.erase(cp.find(arr[0]));
        cp.erase(cp.find(arr[idx]));
        x = arr[0] + arr[idx];
        // cout<<x<<" "<<arr[0]<<" "<<arr[idx]<<"\n";
        lli curMax = arr[0];
        bool allOK = true;
        vc v;
        v.push_back({curMax, arr[idx]});
        while(!cp.empty()) 
        {
            lli toRem = *cp.rbegin();
            cp.erase(cp.find(toRem));
            // curMax = toRem + something -> Something = curMax - torRem
            lli sth = curMax - toRem;
            if(cp.find(sth) == cp.end())
            {
                allOK = false;
                break;
            }
            else
            {
                // cp.erase(cp.find(toRem));
                cp.erase(cp.find(sth));
                curMax = toRem;
                v.push_back({toRem, sth});
            }
        } 
        if(allOK)
        {
            hogya = true;
            ans = v;
            break;
        }
    }
    if(hogya)
    {
        cout<<"YES\n";
        cout<<x<<'\n';
        for(auto x: ans)
        {
            cout<<x.ff<<" "<<x.ss<<'\n';
        }
    }
    else
    {
        cout<<"NO\n";
    }
}
int main()

{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
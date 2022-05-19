#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli,lli>;


#define ff first
#define ss second
#define all(x) begin(x), end(x)
#define xarr(x, n) x, x + n
#define FOR(i, n) for(int i = 0; i<n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0; i--)

const int maxN =2e5 + 5;
int main()
{
    int n;
    cin>>n;
    multiset<lli>s;
    int cnt = 0;
    FOR(i,n)
    {
        lli x;
        cin>>x;
        auto it = s.upper_bound(x);
        if(it == s.end())
        {
            cnt++;
            s.insert(x);
        }
        else
        {
            s.erase(it);
            s.insert(x);
        }
    }
    cout<<cnt<<'\n';
}
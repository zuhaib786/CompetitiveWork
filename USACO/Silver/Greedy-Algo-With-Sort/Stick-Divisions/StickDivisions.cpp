#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
using vc = vector<lli>;

#define ff first
#define ss second
#define FOR(i, n) for(int i = 0; i<n; i++)
#define ROF(i, n) for(int i = n- 1; i>=0; i--)

#define all(x) begin(x), end(x)
#define xarr(x, n) x, x + n

const int maxN = 2e5 + 5;
int main()
{
    lli x, n;
    cin>>x>>n;
    multiset<lli>s;
    FOR(i, n)
    {
        lli k;
        cin>>k;
        s.insert(k);
    }
    lli cost = 0;
    while(s.size()!=1)
    {
        auto it = s.begin();
        lli l1 = *it;
        lli l2 = *next(it);
        cost += (l1  + l2);
        s.erase(s.find(l1));
        s.erase(s.find(l2));
        s.insert(l1 + l2);
    }
    cout<<cost<<'\n';
    
}

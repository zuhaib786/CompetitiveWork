#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
using vc = vector<lli, lli>;

#define ff first
#define ss second
#define FOR(i,n) for(int i = 0; i < n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0; i--)

const int maxN = 1e5 + 5;

class DSU
{
    public:
    vector<int>rank;
    vector<int>parent;
    DSU(int n)
    {
        rank = vector<int>(n, 0);
        parent  = vector<int>(n,0);
        for(int i = 0; i< n; i++)
        {
            parent[i] = i;
        }
    }
    int Find(int a)
    {
        if( a== parent[a])
        return a;
        return a = Find(parent[a]);
    }
    void Union(int a , int b)
    {
        a = Find(a);
        b = Find(b);
        if(a==b)
        return;
        if(rank[a] >rank[b])
        {
            parent[b] = a;
        }
        else if (rank[a]<rank[b])
        {
            parent[a] = b;
        }
        else
        {
            parent[b] = a;
            rank[a]++;
        }
    }
    int maxCount()
    {
      //get maximum number of elements in a collection
        int ans = 0;
        map<int,int>m;
        for(int i = 0; i<parent.size(); i++)
        {
            m[parent[i]]++;
        }
        for(auto x: m)
        {
            ans = max(ans,x.second);
        }
        return ans;
    }
};
lli getMin(set<lli> & s, lli x)
{
    auto it = s.lower_bound(x);
    if(it == s.end())
    {
        lli j = *prev(it);
        return abs(x - j);
    }
    if(it == s.begin())
    {
        lli j = *it;
        return abs( x- j);
    }
    return min(abs(x - *prev(it)), abs(x  - *it));
}
lli getMin(set<lli>&s1, set<lli>&s2)
{
    if(s1.size() > s2.size())
    {
        return getMin(s2, s1);
    }
    lli ans = LONG_MAX;
    for(auto x: s1)
    {
        ans = min(ans, getMin(s2, x));
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        DSU ds(n);
        FOR(i, m)
        {
            int a, b;
            cin>>a>>b;
            a--, b--;
            ds.Union(a, b);
        }
        int a = ds.Find(0);
        int b = ds.Find(n - 1);
        if(a == b)
        {
            cout<<0<<'\n';
            continue;
        }
        // set<lli>s1, s2, s3;
        map<int, set<lli>>mp;
        FOR(i, n)
        {
            int k = ds.Find(i);
            mp[k].insert(i);
        }
        lli ans = LONG_MAX;
        for(auto x: mp)
        {
            lli dis1 = getMin(mp[a], x.ss);
            lli dis2 = getMin(mp[b], x.ss);
            // cout<<dis1<<" "
            ans = min(ans, dis1*dis1 + dis2 * dis2);
        }
        cout<<ans<<'\n';
        


    }
}
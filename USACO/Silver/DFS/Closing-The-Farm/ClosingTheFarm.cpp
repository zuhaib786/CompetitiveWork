#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
#define FOR(i, n) for(int i = 0; i < n; i++)
#define ff first
#define ss second
class DSU
{
    public:
    vector<int>parent;
    vector<int>rank;
    int comp;
    DSU(int n)
    {
        parent.resize(n, 0);
        rank.resize(n, 0);
        FOR(i, n)
        {
            parent[i] = i;
        }
        comp =n;
    }
    int Find(int a)
    {
        if(parent[a] == a)
        return a;
        return parent[a] = Find(parent[a]);
    }
    void Union(int a, int b)
    {
        // cout<<"Call for Union "<<a<<" "<<b<<'\n';
        a = Find(a);
        b = Find(b);
        if(a == b)
        return ;
        if(rank[a] < rank[b])
        {
            parent[a] = b;
            // return;
        }
        else if (rank[b] < rank[a])
        {
            parent[b] = a;
            // return;
        }
        else
        {
            parent[a] = b;
            rank[b]++;
        }
        comp--;
    }
    int getComp()
    {
        return comp;
    }
    bool validate(int k)
    {
        // cout<<"Comp = "<<comp<<'\n';
        return comp - k == 1;
    }
};
const int maxN = 3e3 + 7;
pii edges[maxN];
int n, m;
set<int>s;
void solve()
{
    DSU ds(n);
    FOR(i, m)
    {
        int a = edges[i].ff, b = edges[i].ss;
        // cout<<"a = "<<a<<" b = "<<b<<'\n';
        if(s.find(a)!=s.end()|| s.find(b)!=s.end())
        {
            continue;
        }
        ds.Union(a, b);
    }
    if(ds.validate(s.size()))
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }

}
int main()
{
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    cin>>n>>m;
    FOR(i, m)
    {
        int a, b;
        cin>>a>>b;
        a--, b --;
        edges[i] = {a, b};
    }
    solve();
    FOR(i, n -1)
    {
        int a;
        cin>>a;
        a--;
        s.insert(a);
        solve();
    }
    
}
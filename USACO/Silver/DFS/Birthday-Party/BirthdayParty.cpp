#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
using vc = vector<lli, lli>;
#define ff first
#define ss second

#define FOR(i, n) for(int i = 0; i< n ; i++)
#define ROF(i, n) for(int i = n - 1; i >= 0; i--)
class DSU
{
    public:
    vector<int>rank;
    vector<int>parent;
    int nc;
    DSU(int n)
    {
        rank = vector<int>(n, 0);
        parent  = vector<int>(n,0);
        for(int i = 0; i< n; i++)
        {
            parent[i] = i;
        }
        nc = n;
    }
    int Find(int a)
    {
        while(parent[a]!= a)
        {
            a = parent[a];
        }
        return a;
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
        nc--;
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
int main()
{
    while(true)
    {
        bool ans = false;
        int n, m;
        cin>>n>>m;
        if(n == 0)
        {
            break;
        }
        pii edges[m];
        FOR(i, m)
        {
           cin>>edges[i].ff>>edges[i].ss;
        }
        FOR(i, m)
        {
            DSU ds(n);
            FOR(j, m)
            {
                if(j!=i)
                {
                    ds.Union(edges[j].ff, edges[j].ss);
                }
            }
            ans = ans | (ds.nc != 1);
        }
        if(ans)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }


    }
    
}
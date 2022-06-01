#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
#define ff first
#define ss second
#define FOR(i, n) for(int i = 0; i<n; i++)

const int maxN = 1e3 + 3;
struct  edge
{
    lli i, j, dis;
};
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
vector<edge>v;
pii arr[maxN];
int main()
{
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int n;
    cin>>n;
    FOR(i, n)
    {
        cin>>arr[i].ff>>arr[i].ss;
    }
    FOR(i, n)
    {
        for(int j = i + 1; j<n; j++)
        {
            lli dis = 0;
            dis += (arr[i].ff - arr[j].ff)*(arr[i].ff - arr[j].ff);
            dis += (arr[i].ss - arr[j].ss)* (arr[i].ss - arr[j].ss);
            v.push_back({i, j, dis});
        }
    }
    sort(v.begin(), v.end(), [](edge e1, edge e2)
    {
        return e1.dis < e2.dis;
    });
    DSU ds(n);
    lli mx = 0;
    for(auto x: v)
    {
        ds.Union(x.i, x.j);
        if(ds.nc  == 1)
        {
            mx = x.dis;
            break;
        }
    }
    cout<<mx<<'\n';


}
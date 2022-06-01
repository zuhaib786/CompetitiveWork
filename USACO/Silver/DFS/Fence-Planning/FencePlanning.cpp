#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
using vc = vector<lli>;
#define ff first
#define ss second
#define FOR(i, n) for(int i = 0; i < n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0; i--)

const int maxN = 1e5 + 5;

vector<int>adj[maxN];
int parent[maxN];
int trank[maxN];
int Find(int a)
{
    if(a == parent[a])
        return a;
    return parent[a] = Find(parent[a]);
}
void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if(a == b)
    {
        return;
    }
    if(trank[a] < trank[b])
    {
        parent[a] = b;
    }
    else if (trank[b] < trank[a])
    {
        parent[b] = a;
    }
    else 
    {
        parent[a]= b;
        trank[b]++;
    }
}
map<int, vector<int>> getEachCollection(int n)
{
    map<int, vector<int>>m;
    FOR(i, n)
    {
        int a = Find(i);
        m[a].push_back(i);
    }
    return m;
}
pii arr[maxN];
int main()
{
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    FOR(i, n)
    {
        cin>>arr[i].ff>>arr[i].ss;
    }
    FOR(i, n)
    {
        parent[i] = i;
    }
    memset(trank, 0, sizeof(trank));
    for(int i = 0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        a-- , b--;
        Union(a, b);
    }
    map<int, vector<int>>mp = getEachCollection(n);
    lli best  = INT_MAX;
    for(auto x: mp)
    {
        lli xmin = INT_MAX, xmax = INT_MIN, ymin = INT_MAX, ymax = INT_MIN;
        for(auto p: x.ss)
        {
            xmin = min(xmin, arr[p].ff);
            xmax = max(xmax, arr[p].ff);
            ymin = min(ymin, arr[p].ss);
            ymax = max(ymax, arr[p].ss);
        }
        best = min(best, 2*((xmax - xmin) + (ymax - ymin)));
    }
    cout<<best<<'\n';

}
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
using vc = vector<lli>;

#define ff first
#define ss second
#define FOR(i, n) for(int i = 0; i< n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0; i--)

const int maxN = 1e5 + 5;
vector<int>adj[maxN];
int color[maxN];
lli rc = 0;
lli bc = 0;
void dfs(int u, int par)
{
    for(auto x: adj[u])
    {
        if(x!=par)
        {
            color[x] = color[u]^1;
            rc += color[x] == 0;
            bc += color[x] == 1;
            dfs(x, u);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    memset(color, - 1, sizeof(color));
    for(int i = 0; i < n - 1; i++)
    {
        int u , v;
        cin>>u>>v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    color[0] = 0;
    rc++;
    dfs(0,  - 1);
    cout<<(rc * bc - n  + 1)<<'\n';
}
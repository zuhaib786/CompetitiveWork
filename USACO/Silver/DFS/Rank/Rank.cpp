#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
using vc = vector<lli>;

#define ff first
#define ss second
#define FOR(i, n) for(int i = 0; i < n; i++)
#define ROF(i, n) for(int i = n -1 ; i>=0; i--)

const int maxN = 21;
vector<int>adj[maxN];
int visited[maxN];
int ans;
void dfs(int i, int check)
{
    visited[i] = 1;// under process.
    for(auto x: adj[i])
    {
        if(visited[x] == 2)
        {
            continue;
        }
        if(visited[x] == 1)
        {
            // cycle found;
            if(x == check)
            ans = 1;
            continue;
        }
        dfs(x, check);
    }
    visited[i] = 2; //completed DFS
}
int solve(int i)
{
    memset(visited, - 1, sizeof(visited));
    ans = 0;
    dfs(i, i);
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    FOR(i, m)
    {
        int a, b, c,d;
        cin>>a>>b>>c>>d;
        a--, b--;
        if(c < d)
        {
            // b is better than a
            adj[b].push_back(a);
        }
        else
        {
            assert(d<c);
            adj[a].push_back(b);
        }
    }
    int ans = 0;
    FOR(i, n)
    {
        ans += solve(i);
    }
    cout<<ans<<'\n';
}
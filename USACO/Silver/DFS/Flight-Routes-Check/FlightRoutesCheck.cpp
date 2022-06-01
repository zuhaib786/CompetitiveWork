#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
#define ff first
#define ss second
#define FOR(i, n) for(int i = 0; i<n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0; i--)

const int maxN = 1e5 + 5;
vector<int>adj[maxN];
vector<int>rev[maxN];
int ct1 = 0;
int ct2 = 0;
bool visited[maxN];
bool revVisited[maxN];
void dfs(int i)
{
    visited[i] = true;
    for(auto x: adj[i])
    {
        if(!visited[x])
        {
            dfs(x);
        }
    }
}
void revdfs(int i)
{
    revVisited[i] = true;
    for(auto x: rev[i])
    {
        if(!revVisited[x])
        {
            revdfs(x);
        }
    }
}
int main()
{
    // If all the vertices in graph are reachable from 0
    // and if all the vertices in revgraph are reachable from 0 which means 0 is reachable from all the vertices 
    // Then we have complete connections.
    int n, m;
    cin>>n>>m;
    FOR(i, m)
    {
        int a, b;
        cin>>a>>b;
        a--, b--;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }
    memset(visited, false, sizeof(visited));
    memset(revVisited, false, sizeof(revVisited));
    dfs(0);
    revdfs(0);
    for(int i = 0; i<n; i++)
    {
        if(!visited[i] || !revVisited[i])
        {
            cout<<"NO\n";
            if(!visited[i])
            cout<<1<<" "<<i + 1<<'\n';
            else
            cout<<i + 1<<" "<<1<<'\n';
            return 0;
        }
    }
    cout<<"YES\n";
}
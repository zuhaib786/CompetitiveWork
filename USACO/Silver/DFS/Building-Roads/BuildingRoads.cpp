#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
using vc = vector<lli>;

#define ff first
#define ss second
#define FOR(i, n) for(int i = 0; i<n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0; i--)

const int maxN = 1e5 + 5;

vector<int>adj[maxN];
bool visited[maxN];
void dfs(int v)
{
    visited[v] = true;
    for(auto x: adj[v])
    {
        if(!visited[x])
        {
            dfs(x);
        }
    }
    return;
}
int main()
{
    int n,m;
    cin>>n>>m;
    FOR(i, m)
    {
        int a, b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(visited, false, sizeof(visited));
    vector<int>comp;
    FOR(i, n)
    {
        if(!visited[i])
        {
            comp.push_back(i + 1);
            dfs(i);
        }
    }
    cout<<comp.size() -1 <<'\n';
    FOR(i, comp.size() - 1)
    {
        cout<<comp[i]<<" "<<comp[i + 1]<<'\n';
    }

}
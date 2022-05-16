
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
const int maxN = 1000;
// vector<int>adj[maxN];
vector<int>rev[maxN];
stack<int>s;
int visited[maxN];
void dfs(int v)
{
    visited[v] = true;
    for(auto x: rev[v])
    {
        if(!visited[x])
        {
            // visited[x] = true;
            dfs(x);
        }
    }
    s.push(v);
}
void setIO(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
int main()
{
    setIO("factory");
    int n;
    cin>>n;
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin>>a >> b;
        a -- , b -- ;
        // adj[a].push_back(b);
        rev[b].push_back(a);
    }
    memset(visited, 0, sizeof(visited));
    // Find Topological order of reverse graph
    // For that we run dfs on reverse graph
    for(int i = 0; i<n; i++)
    {
        memset(visited, 0, sizeof(visited));
        dfs(i);
        int ans = true;
        for(int j = 0; j<n; j++)
        {
            ans = ans & (visited[j] == 1);
        }
        if(ans)
        {
            cout<<i + 1<<'\n';
            return 0;
        }
    }
    cout<<-1<<'\n';


}
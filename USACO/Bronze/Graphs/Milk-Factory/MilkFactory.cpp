
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
    for(int i = 0; i < n; i++)
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
    dfs(0);
    vector<int>toporder;
    while(!s.empty())
    {
        toporder.push_back(s.top());
        s.pop();
    }
    if(toporder.size() != n)
    {
        cout<<-1<<'\n';
    }
    else
    {
        int dp[n];
        memset(dp, 0, sizeof(dp));
        dp[toporder[0]] = 1;
        for(int i = 0; i<n; i++)
        {
            if(dp[toporder[i]] != 1)
            {
                cout<<-1<<'\n';
                return 0;
            }
            for(auto x: rev[toporder[i]])
            {
                dp[x] = 1;
            }
        }
        cout<<toporder[0] + 1<<'\n';
    }

}
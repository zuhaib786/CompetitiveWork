#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
const int maxN = 2e5 + 5;
vector<int>adj[maxN];
int ans[maxN];
void dfs(int u, int par)
{
    for(auto v: adj[u])
    {
        if(v != par)
        {
            dfs(v, u);
        }
    }
    int sec_amt = 0;
    for(auto v: adj[u])
    {
        if(v != par)
        {
            sec_amt += ans[v];
        }
    }
    ans[u] = max(ans[u], sec_amt);
    for(auto v: adj[u])
    {
        if(v != par)
        {
            int amt = 0;
            for(auto x: adj[v])
            {
                if( x != u)
                {
                    amt += ans[x];
                }
            }
            ans[u] = max(ans[u], sec_amt - ans[v] + amt + 1);
        }
    }   
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    memset(ans, 0, sizeof(ans));
    for(int i = 0; i< n - 1; i++)
    {
        int a, b;
        cin>>a>>b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, - 1);
    int cnt = *max_element(ans, ans + n);
    cout<<cnt<<'\n';
}
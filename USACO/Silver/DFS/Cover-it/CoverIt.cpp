#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
using vc = vector<lli>;

const int maxN = 2e5 + 5;
int color[maxN];
void dfs(int u, vector<vector<int>> & adj)
{
    for(auto x: adj[u])
    {
        if(color[x] ==-1)
        {
            color[x] = color[u] ^ 1;
            dfs(x, adj);
        }
    }
}
int main()
{
    int t;
    cin>>t;
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(NULL);
    while(t--)
    {
     
        memset(color,  - 1, sizeof(color));
        int n, m;
        cin>>n>>m;
        // cout<<"why the func  is this happening\n";
        vector<vector<int>>adj(n);
        
        for(int i = 0; i < m; i++)
        {
            int a, b;
            cin>>a>>b;
            a--, b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        // cout<<"why the func  is this happening\n";
        color[0] = 0;
        dfs(0, adj);
        int bc  = 0, wc = 0;
        for(int i  =0; i<n; i++)
        {
            wc += color[i] == 0;
            bc += color[i] == 1;
        }
        if(wc > n/2)
        {
            cout<<bc<<'\n';
            for(int i = 0; i< n; i++)
            {
                if(color[i] == 1)
                    cout<<i + 1<<" ";
            }
            cout<<'\n';
        }
        else
        {
            cout<<wc<<'\n';
            for(int i = 0; i< n; i++)
            {
                if(color[i] == 0)
                    cout<<i + 1<<' ';
            }
            cout<<'\n';
        }
    }
}
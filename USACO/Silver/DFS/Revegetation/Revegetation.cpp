#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
using vc = vector<lli>;

#define ff first
#define ss second


const int maxN = 1e5  + 5;
vector<pii>adj[maxN];
bool visited[maxN];
int color[maxN];
bool dfs(int i)
{
    if(visited[i])
    {
        return true;
    }
    // cout<<"DFS ( "<<i<<") "<<color[i]<<'\n';
    visited[i] = true;
    bool accum = true;
    for(auto x: adj[i])
    {
        // cout<<i<<" "<<x.ff<<" "<<x.ss<<'\n';
        if(visited[x.ff])
        {
            if(x.ss == 0 && color[x.ff] != color[i])
            {
                // cout
                return false;
            }
            if(x.ss == 1 && color[x.ff] == color[i])
            {
                return false;
            }
        }
        else
        {
            if(x.ss == 0)
            color[x.ff] = color[i];
            else
            color[x.ff] = color[i] ^ 1; 
            accum = accum && dfs(x.ff);
        }
    }
    return accum;
}
string to_binary(lli x)
{
    string ans = "";
    while(x>0)
    {
        ans += to_string( x% 2 );
        x/=2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    freopen("revegetate.in", "r",stdin);
    freopen("revegetate.out", "w", stdout);
    int n , m;
    cin>>n>>m;
    memset(visited, false, sizeof(visited));
    string ans = "1"; 
    for(int i = 0; i< m; i++)
    {
        char c; int u, v;
        cin>>c>>u>>v;
        u--, v--;
        if(c == 'S')
        {
            adj[u].push_back({v, 0});
            adj[v].push_back({u, 0});
        }
        else
        {
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 1});
        }
    }
    // for(int i = 0; i<n; i++)
    // {
    //     for(auto x: adj[i])
    //     {
    //         cout<<i<<" "<<x.ff<<" "<<x.ss<<'\n';
    //     }
    // }
    memset(color, - 1, sizeof(color));
    lli cnt = 1;
    bool poss = true;
    for(int i = 0; i<n; i++)
    {

        if(visited[i])
        continue;
        color[i] = 0;
        poss = poss && dfs(i);
        ans += '0';
    }
    // cout<<poss<<" "<<cnt<<'\n';
    if(poss)
    {
        cout<<ans<<'\n';
    }
    else
    {
        cout<<0<<'\n';
    }
}
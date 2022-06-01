
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
#define ff first
#define ss second
int cost = 0;
void dfs(vector<pii>tree[], int v, int par)
{
    // int ct = 0;

    for(auto x: tree[v])
    {
        // cout<<x.ff<< " "<<x.ss<<'\n';
        if(x.ff!=par)
        {
            // ct++;
            cost += x.ss;
            dfs(tree, x.ff, v );
        }
    }
    
}
int minimumDistance(int n, int m, vector<vector<int>> &roads){
    // Write your code here.
    vector<lli>dis(n,INT_MAX);
    dis[0] = 0;
    vector<pii>adj[n];
    vector<int>prev(n, - 1);
    for(auto edge : roads)
    {
        int a = edge[0];
        a--;
        int b = edge[1];
        b--;
        int d = edge[2];
        // cout<<a<<" "<<b<<" "<<d<<'\n';
        adj[a].push_back({b, d});
        adj[b].push_back({a, d});
    }
    set<pii>s;
    s.insert({0, 0});
    while(!s.empty())
    {
        pii p  = *s.begin();
        s.erase(s.find(p));
        for(auto x: adj[p.ss])
        {
            // cout<<p.ss<<" "<<p.ff<<" "<<x.ss<<" "<<x.ff<<'\n';
            if(dis[p.ss] + x.ss < dis[x.ff])
            {
                dis[x.ff] = dis[p.ss] + x.ss ;
                prev[x.ff] = p.ss;
                s.insert({  dis[p.ss] + x.ss, x.ff});
            }
        }
    }
    vector<pii>tree[n];
    // for(int i = 0; i<n; i++)
    // {
    //     cout<<prev[i]<<", "<<dis[i]<<"---";
    // }
    // cout<<'\n';
    for(int i = 0; i<n; i++)
    {
        if(prev[i]!=-1)
        {
            // cout<<"HELLO\n";
            lli distance = dis[i] - dis[prev[i]];
            cout<<distance<<" "<<prev[i]<<" "<<i<<"\n";
            tree[i].push_back({prev[i], distance});
            tree[prev[i]].push_back({i, distance});
        }
    }
    dfs(tree, 0, - 1);
    
    return cost;
    
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        // cout<<n<<m<<'\n';
        vector<vector<int>>roads;
        for(int i = 0; i< m; i++)
        {
            int a, b, c;
            cin>>a>>b>>c;
            roads.push_back({a, b, c});
        }
        cout<<minimumDistance(n, m, roads)<<'\n';
    }
}
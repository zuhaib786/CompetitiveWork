#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;

#define ff first
#define ss second

const int maxN = 101;
set<pii>s;
set<pii>visited;
set<pii>unlit;
map<pii, vector<pii>>adj;
int dx[] = {1,  - 1, 0 , 0 };
int dy[] = {0, 0, - 1, 1};
void printUnlit()
{
    cout<<"Printing Unlit\n";
    for(auto x: unlit)
    {
        cout<<x.ff<<" "<<x.ss<<'\n';
    }
    cout<<"\n";
}
void printIlluminated()
{
    cout<<"printing s\n";
    for(auto x: s)
    {
        cout<<x.ff<<" "<<x.ss<<'\n';
    }
}
int main()
{
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    for(int i = 0 ; i < m; i++)
    {
        int x, y, a, b;
        cin>>x>>y>>a>>b;
        adj[{x,y}].push_back({a, b});
    }
    stack<pii>dfs;
    dfs.push({1, 1});
    s.insert({1, 1});
    lli ctIter = 0;
    while(!dfs.empty())
    {
        ctIter++;
        assert(ctIter <= 1e6 + 6);
        pii p = dfs.top();
        // cout<<p.ff<<" "<<p.ss<<'\n';
        visited.insert(p);
        for(int i =0; i<4; i++)
        {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(nx <= n && nx > 0 && ny <= n && ny > 0)
            {
                unlit.insert({nx, ny});// part of cc
            }
        }
        for(auto w: adj[p])
        {
            s.insert(w);
            if(unlit.find(w) != unlit.end() && visited.find(w) == visited.end())
            {
                dfs.push(w);
                // unlit.erase(w);
            }
        }
        // printUnlit();
        dfs.pop();
        for(int i =0; i<4; i++)
        {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(nx <= n && nx > 0 && ny <= n && ny > 0)
            {
                if(visited.find({nx, ny}) == visited.end())
                {
                    dfs.push({nx, ny});
                }
            }
        }
    }
    int ct = 0;
    for(auto x: s)
    {
        if(unlit.find(x) != unlit.end())
        {
            ct++;
        }
    }
    // printIlluminated();
    cout<<ct- 1<<'\n';
}
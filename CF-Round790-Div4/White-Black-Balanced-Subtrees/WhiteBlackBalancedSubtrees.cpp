#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
const int maxN = 4e4 + 5;
int black[maxN];
int white[maxN];
string s;
void dfs(int u, int par, vector<int>adj[])
{
    if(s[u] == 'B')
    {
        black[u]++;
    }
    else
    {
        white[u]++;

    }
    for(auto x: adj[u])
    {
        if(x!=par)
        dfs(x, u, adj);
        if(x!=par)
        {
            black[u] += black[x];
            white[u] += white[x];
        }
    }

}
void solve()
{
    int n;
    cin>>n;
    vector<int>adj[n];
    for(int i = 0; i<n - 1; i++)
    {
        int k;
        cin>>k;
        k--;
        adj[k].push_back(i + 1);
    }
    memset(black, 0, sizeof(black));
    memset(white, 0, sizeof(white));
    cin>>s;
    dfs(0, - 1, adj);
    int cnt = 0;
    for(int i = 0; i<n; i++)
    {
        cnt += (black[i] == white[i]);
    }
    cout<<cnt<<'\n';
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }   
}

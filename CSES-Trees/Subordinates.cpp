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
            ans[u]++;
            dfs(v, u);
            ans[u] += ans[v];
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
        int k;
        cin>>k;
        k--;
        adj[k].push_back(i + 1);
    }
    dfs(0, - 1);
    for(int i = 0; i< n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<'\n';
}
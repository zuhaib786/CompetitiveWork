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
            ans[v] = ans[u] + 1;
            dfs(v, u);
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
    int idx = max_element(ans, ans + n) - ans;
    memset(ans, 0, sizeof(ans));
    dfs(idx , -1);
    cout<<*max_element(ans, ans + n)<<'\n';

}
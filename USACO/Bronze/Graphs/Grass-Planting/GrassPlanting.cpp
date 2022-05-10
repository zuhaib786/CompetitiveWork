#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 5;
vector<int>adj[maxN];
void setIO(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
int main()
{
    setIO("planting");
    int n;
    cin>>n;
    for(int i = 0; i<n - 1; i++)
    {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 0;
    for(int i = 1 ; i<= n; i++)
    {
        // cout<<i<<" "<<adj[i].size() + 1<<'\n';
        ans = max(ans, (int)adj[i].size() + 1);
    }
    cout<<ans<<'\n';
    
}
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
const int maxN = 1e4;
vector<int>adj[maxN];
int arr[maxN][4];

void setIO(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
int main()
{
    memset(arr,0,sizeof(arr));
    setIO("revegetate");
    int n,m;
    cin>>n>>m;
    for(int i = 0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool visited[n];
    int color[n];
    memset(visited, 0, sizeof(visited));
    memset(color, -1, sizeof(color));
    for(int i = 0; i<n; i++)
    {
        int col = -1;
        for(int j = 0; j<4; j++)
        {
            if(arr[i][j] == 0)
            {
                col = j;
                arr[i][j] = 1;
                break;
            }
        }
        color[i] = col;
        // cout<<i<<" "<<col<<'\n';
        assert(col != -1);
        for(auto x: adj[i])
        {
            arr[x][col] = 1;
        }
    }
    
    int cnt = 1;
    map<int, int>mp;
    for(int i = 0; i<n; i++)
    {
        if(!mp.count(color[i]))
        {
            mp[color[i]]  = cnt;
            cnt++;
        }
        cout<<mp[color[i]];
    }
    cout<<'\n';
}
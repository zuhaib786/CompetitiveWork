#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;

#define ff first
#define ss second
#define FOR(i, n) for(int i = 0; i < n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0; i--)

const int maxN = 51;
string grid[maxN];
int visited[maxN][maxN];
int dx[] = {1, - 1, 0 , 0 };
int dy[] = {0, 0 , 1, - 1};
void dfs(int i, int j, int n, int m)
{
    if(i<0 || j<0 || i>=n || j>=m)
    return;
    if(visited[i][j] || grid[i][j] == '#')
    return;
    visited[i][j] = 1;
    for(int k = 0; k < 4; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        dfs(x,y, n, m);
    }
}
void solve()
{
    int n, m;
    cin>>n>>m;
    FOR(i, n)
    {
        cin>>grid[i];
    }
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m;j++)
        {
            if(grid[i][j] == 'B')
            {
                for(int k = 0; k< 4; k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x>=0 && x< n && y>=0 && y<m)
                    {
                        if(grid[x][y] == 'G')
                        {
                            cout<<"No\n";
                            return;
                        }
                        if (grid[x][y] == '.')
						{ 

							grid[x][y] = '#'; 

						}
                    }
                }
            }
        }
    }
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m;j++)
        {
            if(grid[i][j] == 'B')
            {
                for(int k = 0; k< 4; k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x>=0 && x< n && y>=0 && y<m)
                    {
                        
                        grid[x][y] = '#';
                        
                    }
                }
            }
        }
    }

    memset(visited, 0, sizeof(visited));
    dfs(n - 1, m - 1, n, m);
    for(int i = 0 ; i  <n; i++)
    {
        for(int j = 0; j< m; j++)
        {
            if(grid[i][j] == 'G' && !visited[i][j])
            {
                cout<<"No\n";
                return;
            }
        }
    }
    cout<<"Yes\n";
    return;
    
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
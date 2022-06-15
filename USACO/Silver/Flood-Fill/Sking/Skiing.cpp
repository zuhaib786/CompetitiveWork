#include<bits/stdc++.h>
using namespace std;
using lli =  long long int;
using pii = pair<lli, lli>;
using tii = tuple<lli, lli, lli>;
#define ff first
#define ss second

int dx[] = {1,  - 1, 0 , 0 };
int dy[] = {0 , 0 , 1, - 1};
const int maxN = 501;
lli grid[maxN][maxN];
int waylands[maxN][maxN];
lli visited[maxN][maxN];
int main()
{
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>grid[i][j];
        }
    }
    int sx = -1;
    int sy = -1;
    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>waylands[i][j];
            if(waylands[i][j] == 1)
            {
                sx = i;
                sy = j;
            }
        }
    }
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            visited[i][j] = LONG_MAX;
        }
    }
    visited[sx][sy] = 0;
    multiset<vector<lli>>s;
    s.insert({0,sx, sy });
    while(!s.empty())
    {
        vector<lli> p = *s.begin();
        s.erase(s.find(p));
        
        lli d = p[0];
        for(int i = 0; i<4; i++)
        {
            int x = p[1] + dx[i];
            int y = p[2] + dy[i];
            if(x>=0 && x < n && y>=0 && y < m)
            {
                if(visited[x][y] > max(d, abs(grid[p[1]][p[2]] - grid[x][y])))
                {
                    visited[x][y] = max(d, abs(grid[p[1]][p[2]] - grid[x][y]));
                    s.insert({visited[x][y], x, y});
                }
            }
            
        }
    }
    lli ans = 0;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(waylands[i][j] == 1)
            {
                ans = max(ans, visited[i][j]);
            }
        }
    }
    cout<<ans<<'\n';
}
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<int, int>;
#define ff first
#define ss second
const int maxN = 1e3 + 3;
int grid[2*maxN][2*maxN];
int dx[] = {1, - 1, 0, 0};
int dy[] = {0, 0, 1, - 1};
pii avg(pii p1, pii p2)
{
    return {(p1.ff + p2.ff)/2 , (p1.ss + p2.ss)/2};
}
pii nextPos(pii p, char c)
{
    if( c == 'N')
    {
        return {p.ff   +  2, p.ss};
    }
    if( c== 'S')
    return {p.ff - 2, p.ss};
    if( c== 'E')
    {
        return {p.ff , p.ss + 2};
    }
    if( c == 'W')
    return {p.ff , p.ss - 2};
    assert(false);
    return {- 1,  - 1};
}
int xoffset = 0;
int yoffset = 0;

int main()
{
    freopen("gates.in", "r", stdin);
    freopen("gates.out", "w", stdout);
    int n;
    cin>>n;
    string s;
    cin>>s;
    pii p = {0, 0};
    for(char c: s)
    {
        p = nextPos(p, c);
        xoffset = min(p.ff, xoffset);
        yoffset = min(p.ss, yoffset);
    }
    p = {abs(xoffset) + 1, abs(yoffset) + 1};
    memset(grid, 0, sizeof(grid));
    grid[p.ff][p.ss] = 1;
    
    for(auto c: s)
    {
        pii p1 = p;
        p = nextPos(p, c);
        p1 = avg(p1, p);
        grid[p.ff][p.ss] = 1;
        grid[p1.ff][p1.ss] = 1;
    }

    int ct = 0;
    for(int i = 0; i<2*maxN; i++)
    {
        for(int j = 0; j<2*maxN; j++)
        {
            if(grid[i][j] == 0 )
            {
                ct++;
                // cout<<"All done\n";
                queue<pii>q;
                q.push({i, j});
                while (!q.empty())
                {
                    pii p = q.front();
                    q.pop();
                    if(p.ff < 0 || p.ff >= 2*maxN || p.ss < 0 || p.ss>= 2*maxN || grid[p.ff][p.ss] == 1)
                    {
                        continue;
                    }
                    else
                    {
                        grid[p.ff][p.ss] = 1;
                        for(int k = 0; k<4; k++)
                        {
                            q.push({p.ff + dx[k], p.ss + dy[k]});
                        }
                    }
                }
                
            }
        }
    }
    cout<<ct - 1<<'\n';
}

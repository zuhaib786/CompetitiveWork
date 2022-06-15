#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;


const int maxN = 1001;
string grid[maxN];
int visited[maxN][maxN];
int dx[] = {1,-1, 0, 0};
int dy[] = {0, 0, 1, -1};
void dfs(int i, int j, int n, int m)
{
    if(i <0 || i>= n || j< 0 || j>= m || grid[i][j] == '#' || visited[i][j] == 1)
    {
        return;
    }
    visited[i][j] = 1;
    for(int k = 0; k<4; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        dfs(x, y, n, m);
    }
}
int main()
{
    memset(visited, 0, sizeof(visited));
    int n, m;
    cin>>n>>m;
    for(int i = 0; i<n; i++)
    {
        cin>>grid[i];
    }
    int ct = 0;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == '.' && visited[i][j] == 0)
            {
                // cout<<i<<" "<<j<<"\n";
                ct++;
                dfs(i, j, n, m);
            }
        }
    }
    cout<<ct<<'\n';
}
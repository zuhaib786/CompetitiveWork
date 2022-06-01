#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
const int maxN = 1e3 + 3;
int grid[maxN][maxN];
int visited[maxN][maxN];
void dfs(int i, int j, pii & p, int n)
{
    if(i <0 || j< 0 || i>= n || j>=n)
        return;
    if(visited[i][j])
        return;
    visited[i][j]  = 1;
    p.first++;
    if(i - 1 < 0 || grid[i -  1][j] == 0)
    {
        p.second++;
        // dfs(i - 1, j, p, n);
    }
    if(i > 0 && grid[i - 1][j]!=0)
    {
        dfs(i -1 , j, p, n);
    }
    if(j - 1< 0 || grid[i][j - 1]  ==  0 )
    {
        p.second++;
        // dfs()
    }
    if(j  > 0 && grid[i][j - 1] != 0)
        dfs(i, j - 1, p, n);


    if(i + 1 >= n || grid[i +  1][j] == 0)
    {
        p.second++;
        // dfs(i - 1, j, p, n);
    }
    if(i <n - 1 && grid[i + 1][j]!=0)
    {
        dfs(i +1 , j, p, n);
    }
    if(j + 1  >= n || grid[i][j + 1]  ==  0 )
    {
        p.second++;
        // dfs()
    }
    if(j  < n - 1 && grid[i][j + 1] != 0)
        dfs(i, j + 1, p, n);
}
int main()
{
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    int n;
    cin>>n;
    for(int i =0 ; i<n; i++)
    {
        string s;
        cin>>s;
        for(int j =0; j<n; j++)
        {
            grid[i][j] = s[j] == '#';
        }
    }
    memset(visited, 0, sizeof(visited));
    // vector<vector<pii>>dp(n, vector<pii>(n, {-1, -1}));
    pii finAns = {0,  - 0};
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(!visited[i][j] && grid[i][j] == 1)
            {
                pii p = {0,0};
                dfs(i, j, p, n);
                p.second = -p.second;
                finAns = max(finAns, p);
            }
        }
    }
    cout<<finAns.first<<" "<<-finAns.second<<'\n';

}
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

void solve()
{
    int n,m;
    cin>>n>>m;
    int arr[n + 1][m + 1];
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<= m; j++)
        {
            cin>>arr[i][j];
        }
    }
    lli ans[n + 1][m + 1];
    for(int i = - m + 1; i<= n - 1; i++)
    {
        lli cnt = 0;
        for(int x = 1 ; x <= n; x++)
        {
            int y = x - i;
            if(y>=1 && y<=m)
            {
                cnt += arr[x][y];
            }
        }
        for(int x = 1 ; x <= n; x++)
        {
            int y = x - i;
            if(y>=1 && y<=m)
            {
                ans[x][y] = cnt;
            }
        }
    }
    for(int i = 2; i<= n +m; i++)
    {
        lli cnt = 0;
        for(int x = 1; x<=n; x++)
        {
            int y = i - x;
            if(1<=y && y<=m)
            {
                cnt += arr[x][y];
            }
        }
        for(int x = 1; x<=n; x++)
        {
            int y = i - x;
            if(1<=y && y<=m)
            {
                ans[x][y] += cnt - arr[x][y];
            }
        }
    }
    lli mx = LONG_MIN;
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            mx = max(mx, ans[i][j]);
        }
    }
    cout<<mx<<'\n';

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

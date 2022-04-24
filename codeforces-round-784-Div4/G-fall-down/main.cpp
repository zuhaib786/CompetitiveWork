#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        vector<string>grid(n);
        for(int i = 0; i<n; i++)
        {
            cin>>grid[i];
        }
        for(int j = 0; j< m; j++)
        {
            int prev =  -1;
            for(int i = n - 1; i>=0 ; i--)
            {
                if(grid[i][j] == '*')
                {
                    if(prev == -1)
                    {
                        continue;
                    }
                    else
                    {
                        grid[prev][j] = '*';
                        grid[i][j] = '.';
                        prev--;
                    }
                }
                else if(grid[i][j] == '.')
                {
                    if(prev == -1)
                    {
                        prev = i;
                    }
                }
                else
                {
                    prev = -1;
                }
            }
        }
        for(auto x : grid)
        {
            cout<<x<<'\n';
        }
    }

    return 0;
}
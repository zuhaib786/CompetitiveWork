#include<bits/stdc++.h>
using namespace std;
#define maxN 1001
string grid[maxN];
string pattern[maxN];
bool check(int R, int r)
{
    bool ans = false;
    for(int i = 0; i <= R -r ; i++ )
    {
        int C = grid[0].size();
        int c = pattern[0].size();
        for(int offset = 0; offset <= C - c; offset++)
        {
            bool poss =true;
            for(int i1 = i ; i1 < i + r; i1++)
            {
                for(int j1 = offset; j1 < offset + c; j1 ++)
                {
                    if(grid[i1][j1] != pattern[i1 - i][j1 - offset])
                    {
                        poss = false;
                        break;
                    }
                }
            }
            ans = ans || poss;
        }
        return ans;
    }
}
string gridSearch(vector<string> G, vector<string> P)
{
    for(int i = 0; i< G.size(); i++)
    {
        grid[i] = G[i];
    }
    for(int i =0; i< P.size(); i++)
    {
        pattern[i] = P[i];
    }
    bool ck = check(G.size(), P.size());
    if(ck)
    return "YES";
    else
    return "NO";
}
int main()
{
    int  t;
    cin>>t;
    while(t--)
    {
        int R, C;
        cin>>R>>C;
        for(int i = 0; i < R; i++)
        {
            cin>>grid[i];
        }
        int r, c;
        cin>>r>>c;
        for(int i = 0; i< r; i++)
        {
            cin>>pattern[i];
        }
        if(check(R, r))
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    
}
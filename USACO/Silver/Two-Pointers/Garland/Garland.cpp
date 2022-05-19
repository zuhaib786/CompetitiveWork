#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
#define ff first
#define ss second
#define FOR(i, n) for(int i = 0; i< n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0; i--)
const int maxN = 1501;
const int alp = 26;
int dp[maxN][maxN][alp];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, 0,sizeof(dp));
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j< n; j++)
        {
            for(int k = 0 ; k<alp; k++ )
            {
                dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k],dp[i ][j][k] + 1);
                if(s[i] - 'a' == k)
                {
                    dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + 1);
                }
            }
        }
    }
    for(int k = 0; k<26; k ++ )
    {
        for(int i = 0; i<n; i++)
        {
            for(int j =0; j<n; j++)
            {
                dp[i  + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
            }
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int a; char c;
        cin>>a>>c;
        int idx = c - 'a';
        cout<<dp[n][a][idx]<<'\n';
    }
}
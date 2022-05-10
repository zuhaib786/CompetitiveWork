#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
void setIO(string name)
{
    cin.tie(0)->sync_with_stdio(0);
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
const int maxN = 11;
int arr[maxN][maxN];
void flip( int x, int y)
{
    for(int i = 0; i<=x; i++)
    {
        for(int j = 0 ; j<=y; j++ )
        {
            arr[i][j]^=1;
        }
    }
}
int main()
{
    setIO("cowtip");
    int n;
    cin>>n;
    
    for(int i = 0; i<n; i++)
    {
        string s;
        cin>>s;
        assert(s.size() == n);
        for(int k = 0; k< n; k++)
        {
            arr[i][k] = s[k] == '1';
        }
    }
    int cnt = 0;
    for(int i = n - 1; i>=0; i--)
    {
        for(int j = n - 1; j>=0; j--)
        {
            if(arr[i][j])
            {
                cnt++;
                flip( i, j);
            }
        }
    }
    cout<<cnt<<'\n';
}
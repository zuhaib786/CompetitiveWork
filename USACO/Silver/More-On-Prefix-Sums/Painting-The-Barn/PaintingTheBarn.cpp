#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
void setIO(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
const int mx = 1001;
int arr[mx][mx];
int main()
{
    setIO("paintbarn");
    int n,k;
    cin>>n>>k;
    memset(arr, 0, sizeof(arr));
    for(int i = 0; i<n; i++)
    {
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        arr[x1][y1]++;
        arr[x1][y2]--;
        arr[x2][y1]--;
        arr[x2][y2]++;
    }
    int ans =0;
    for(int i = 0; i<mx; i++)
    {
        for(int j = 0; j<mx; j++)
        {
            if(i>0)
            {
                arr[i][j] += arr[i - 1][j];
            }
            if(j>0)
            {
                arr[i][j] += arr[i][j - 1];
            }
            if(i> 0 && j>0)
            {
                arr[i][j] -= arr[i - 1][j - 1];
            }
            ans += (arr[i][j]==k);
        }
    }
    cout<<ans<<'\n';
}
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
#define ff  first
#define ss  second
#define FOR(i, n) for(int i = 0; i<n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0 ; i--)
using pii = pair<lli, lli>;
using vc = vector<lli>;
const int maxN = 2e5+ 5;
lli arr[maxN];
lli dp[maxN];
void setIO(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
int main()
{
    setIO("herding");
    int n;
    cin>>n;
    FOR(i, n)
    {
        cin>>arr[i];
    }
    memset(dp, 0, sizeof(dp));
    sort(arr , arr + n);
    lli mnStep = 0;
    if(((arr[n - 2] - arr[0] == n  -2) && (arr[n - 1] - arr[n -2 ]>2)   )|| ((arr[n - 1] - arr[1] == n - 2) && (arr[1] - arr[0]>2)))
    {
        mnStep = 2;
    }
    else
    {
        int j = 0;

        FOR(i, n)
        {
            // lli cnt = 0;
            while(j < n && arr[j] - arr[i]<n)
            {
                j++;
            }
            dp[i] = j - i;
        }
        mnStep = n - *max_element(dp, dp + n);
    }
    lli sg = 0;
    FOR(i, n -1 )
    {
        sg += arr[i +1] - arr[i] - 1; 
    }
    lli mxStep = max(sg - (arr[1] - arr[0] - 1), sg - (arr[n - 1] - arr[n - 2] - 1));
    cout<<mnStep<<"\n"<<mxStep<<'\n';
}
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using vc = vector<lli>;
using pii = pair<lli, lli>;

#define ff first
#define ss second

#define FOR(i,n) for(int i =0; i<n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0; i--)

const int maxN = 1e5 + 5;
lli arr[maxN];
int main()
{
    lli n, x;
    cin>>n>>x;
    FOR(i, n)
    {
        cin>>arr[i];
    }
    sort(arr, arr + n);
    lli curSum =  0;
    int cnt = 0;
    FOR(i, n)
    {
        if(curSum + arr[i] <= x)
        {
            curSum += arr[i];
            cnt++;
            continue;
        }
        break;
        
    }
    cout<<cnt<<'\n';
}
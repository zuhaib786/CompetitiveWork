#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
const int maxN = 2e5 + 5;
lli fw[maxN];
int arr[maxN];
int n;
void update(int idx)
{
    idx ++;
    while(idx <=n)
    {
        fw[idx]++;
        idx += idx &(-idx);
    }
}
lli getSum(int idx)
{
    idx++;
    lli ans = 0;
    while(idx>0)
    {
        ans += fw[idx];
        idx -= idx &(-idx);
    }
    return ans;
}
void solve()
{
    // int n;
    cin>>n;
    map<int, int>m;
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
        m[arr[i]];
    }
    int cnt = 0;
    for(auto x: m)
    {
        m[x.first] = cnt;
        cnt++;
    }
    lli ans  = 0;
    memset(fw, 0, sizeof(fw));
    for(int i = 0; i<n; i++)
    {
        ans += i - getSum(m[arr[i]] - 1);
        update(m[arr[i]]);
        
    }
    cout<<ans<<'\n';
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


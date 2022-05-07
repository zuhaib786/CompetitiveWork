#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
void setIO(string name = "")
{
    if(name.size() == 0)
        return;
    cin.tie(0)->sync_with_stdio(0);
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
int main()
{
    setIO("lifeguards");
    int n;
    cin>>n;
    int arr[10001];
    //i mean from i + 1-i interval is covered
    memset(arr, 0, sizeof(arr));
    pii gaurds[n];
    int sz = 0;
    for(int i= 0; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        gaurds[i] = {l,r};
        for(int j  = l; j<r; j++)
        {
            arr[j]++;
            sz += (arr[j] == 1);
        }
    }
    // cout<<sz<<'\n';
    int mx = 0;
    for(int i = 0; i<n; i++)
    {
        int l = gaurds[i].first;
        int r = gaurds[i].second;
        int cnt = 0;
        for(int j = l; j < r; j++ )
        {
            cnt += (arr[j] == 1);
        }
        // cout<<cnt<<'\n';
        mx = max(mx, sz - cnt);
    }
    cout<<max(mx, 0)<<'\n';
}

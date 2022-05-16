#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int arr[n];
    lli ps[n + 1];
    memset(arr, 0, sizeof(arr));
    memset(ps, 0, sizeof(ps));
    for(int i = 0; i  < n; i++)
    {
        arr[i] = s[i] - '0';
    }
    map<lli , lli>m;
    lli ans = 0;
    m[0] = 1;
    for(int i = 0; i<n; i++)
    {
        ps[i + 1] = ps[i] + arr[i];
        ans += m[ps[i + 1] - (i + 1)];
        m[ps[i + 1] - (i + 1)]++;
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
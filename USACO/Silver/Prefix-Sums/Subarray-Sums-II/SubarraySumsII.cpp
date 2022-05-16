#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int main()
{
    map<lli, int>m;
    lli n, x;
    cin>>n>>x;
    m[0] = 1;
    lli ans = 0;
    lli sum = 0;
    for(int i = 0; i<n; i++)
    {
        lli k;
        cin>>k;
        sum += k;
        // cout<<sum<<m[sum-x]<<"\n";
        ans += m[sum -x ];
        m[sum]++;
    }
    cout<<ans<<'\n';
}
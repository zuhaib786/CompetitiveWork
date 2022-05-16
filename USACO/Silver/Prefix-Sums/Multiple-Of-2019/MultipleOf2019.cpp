#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
const int mod = 2019;
const int inv = 202;
int main()
{
    string s;
    cin>>s;
    int cur = 0;
    map<int, int>m;
    m[0] = 1;
    lli ans = 0;
    lli mul = 1;
    for(int i = 0; i<s.size(); i++)
    {
        cur = cur*10 + (s[i] - '0');
        mul *= inv;
        mul %= mod;
        cur %= mod;
        ans += m[(cur*mul)%mod];
        m[(cur*mul)%mod]++;
    }
    cout<<ans<<'\n';
}
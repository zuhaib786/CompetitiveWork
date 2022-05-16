#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
const lli mod = 1e9 + 7;
const int maxN = 1e5 + 5;
using vc = vector<lli>;
void setIO(string name)
{
    cin.tie(0)->sync_with_stdio(0);
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
using pii = pair<lli, lli>;
#define ff first
#define ss second
pii arr[maxN];
int main()
{
    setIO("triangles");
    int n;
    cin>>n;
    map<lli, vector<lli>>mx;
    map<lli, vector<lli>>my;
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i].ff>>arr[i].ss;
        mx[arr[i].ff].push_back(arr[i].ss);
        my[arr[i].ss].push_back(arr[i].ff);
    }
    for(auto x: mx)
    {
        sort(x.ss.begin(), x.ss.end());
    }
    for(auto y: my)
    {
        sort(y.ss.begin(), y.ss.end());
    }
    map<lli, map<lli, int>>mmx;
    map<lli, map<lli, int>>mmy;
    for(auto x: mx)
    {
        vc v = x.second;
        vc S(v.size(), 0);
        S[0] = v[0];
        for(int i = 1; i<v.size(); i++)
        {
            S[i] = S[i - 1] + v[i];
        }
        for(int i = 0; i<v.size(); i++)
        {
            mmx[x.first][v[i]] = (2*((long long)i + 1) - v.size())*(v[i]) - 2*S[i] + S[v.size() - 1];
            assert(mmy[x.first][v[i]]>=0);
        }
    }
    for(auto x: my)
    {
        vc v = x.second;
        vc S(v.size(), 0);
        S[0] = v[0];
        for(int i = 1; i<v.size(); i++)
        {
            S[i] = S[i - 1] + v[i];
        }
        for(int i = 0; i<v.size(); i++)
        {
            mmy[x.first][v[i]] = (2*((long long)i + 1) - v.size())*(v[i]) - 2*S[i] + S[v.size() - 1];
            assert(mmy[x.first][v[i]]>=0);
        }
    }
    lli ans = 0;
    for(int i = 0; i<n; i++)
    {
        lli x = arr[i].ff;
        lli y = arr[i].ss;
        ans %= mod;
        ans += ((mmx[x][y]%mod)*(mmy[y][x]%mod))%mod;
        ans %= mod;
    }
    cout<<ans<<'\n';
}
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
using vc = vector<lli>;
#define ff first
#define ss second
#define FOR(i, n) for(int i = 0; i<n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0 ; i--)
const int maxN  = 1e5 + 5;
pii ldp[maxN];
pii rdp[maxN];
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char, int>m;
    int j = 0;
    FOR(i, maxN)
    {
        ldp[i] = {0,0};
        rdp[i] = {0,0};
    }
    FOR(i, n)
    {
        m[s[i]]++;
        while(m[s[j]]>=2)
        {
            m[s[j]]--;
            j++;
        }
        ldp[i] = {i - j + 1, m.size()};
    }
    int mxPok = m.size();
    m.clear();
    j = n - 1;
    ROF(i, n)
    {
        m[s[i]]++;
        while(m[s[j]]>=2)
        {
            m[s[j]]--;
            j--;
        }
        rdp[i] = {j - i + 1, m.size()};
    }
    lli ans = INT_MAX;
    FOR(i, n)
    {
        // cout<<ldp[i].ff<<" "<<ldp[i].ss<<" "<<rdp[i].ff<<" "<<rdp[i].ss<<'\n';
        if(ldp[i].ss == mxPok)
        {
            ans = min(ans, ldp[i].ff);
        }
        if(rdp[i].ss == mxPok)
        {
            ans = min(ans, rdp[i].ff);
        }
    }
    cout<<ans<<'\n';
}
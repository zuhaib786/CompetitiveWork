#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
using vc = vector<lli>;
#define ff first
#define ss second
#define FOR(i,n) for(int i = 0; i< n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0; i--)

const int maxN = 2e5 + 5;
pii arr[maxN];
lli numP[4*maxN];
lli ans[maxN];
int main()
{
    int n;
    cin>>n;
    map<lli, int>m;
    map<int, lli>rev;
    m[-1];
    FOR(i,n)
    {
        cin>>arr[i].ff>>arr[i].ss;
        m[arr[i].ff];
        m[arr[i].ss + 1];
    }
    lli cnt = 0;
    for(auto x : m)
    {
        m[x.first] = cnt;
        rev[cnt] = x.first;
        cnt++;
    }
    memset(numP, 0, sizeof(numP));
    memset(ans, 0, sizeof(ans));
    FOR(i,n)
    {
        numP[m[arr[i].ff]]++;
        numP[m[arr[i].ss + 1]]--;
    }
    // lli prev = 0;
    lli curSum = 0;
    FOR(i, cnt - 1)
    {
        
        lli prev = curSum;

        curSum += numP[i + 1];
        // cout<<rev[i + 1]<<" "<<curSum<<'\n';
        int curCnt =  curSum;
        ans[curSum]++;
        assert(rev[i + 1] - rev[i] - 1>=0);
        ans[prev] += (rev[i + 1] - rev[i] - 1);

    }
    FOR(i, n)
    {
        cout<<ans[i + 1]<<" ";
    }
    cout<<'\n';


}
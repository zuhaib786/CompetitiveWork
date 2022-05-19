#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli,lli>;
using vc = vector<lli>;
#define ff first
#define ss second
#define FOR(i, n, k) for(int i = 0; i<n; i+= k)
#define ROF(i, n, k) for(int i = n - 1; i>=0; i-=k)
const int maxN =2e5 + 5;
lli arr[maxN];
lli brr[maxN];
lli rt[maxN];
lli lt[maxN];
int main()
{
    int n,m;
    cin>>n>>m;
    FOR(i, n, 1)
    {
        cin>>arr[i];
    }
    FOR(i, m, 1)
    {
        cin>>brr[i];
    }
    int  j = 0;
    fill(rt,rt + n, INT_MAX);
    fill(lt, lt + n, INT_MAX);
    FOR(i, n, 1)
    {
        while(j < m && brr[j] < arr[i])
        {
            j++;
        }
        if(j == m)
        {
            break;
        }
        rt[i] = brr[j] - arr[i];
    }
    j = m - 1;
    ROF(i, n, 1)
    {
        while(j>=0 && arr[i] < brr[j])
        {
            j--;
        }
        if(j ==  - 1)
        {
            break;
        }
        lt[i] = arr[i] - brr[j];
    }
    lli ans = 0;
    FOR(i, n , 1)
    {
        ans = max(ans, min(lt[i], rt[i]));
    }
    cout<<ans<<'\n';
}

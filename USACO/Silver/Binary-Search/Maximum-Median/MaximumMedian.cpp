#include<bits/stdc++.h>
using namespace std;
using lli = long long int ;
using vc = vector<lli>;


const int maxN = 2e5 + 5;
#define FOR(i, n) for(int i = 0; i<n; i++)
#define ROF(i, n) for(int i = n -1; i>=0; i--)


lli arr[maxN];
bool poss(lli val, lli n, lli k)
{
    lli med = (n - 1)/2;
    lli cost  = 0;
    for(int i = med; i< n; i++)
    {
        cost += max(0ll,  val - arr[i]);
    }
    return cost <=k;
}
int main()
{
    lli n,k;
    cin>>n>>k;
    FOR(i, n)
    {
        cin>>arr[i];
    }
    sort(arr, arr + n);
    lli left = arr[(n - 1)/2];
    lli right = arr[(n - 1)/2] + k + 1;
    lli ans = left;
    while(left <= right)
    {
        lli mid = left + (right - left)/2;
        // cout<<left<<" "<<right<<" " <<mid<<" "<<poss(mid, n,k)<<"\n";
        if(poss(mid, n, k))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid-1;
        }
    }
    cout<<ans<<'\n';
}

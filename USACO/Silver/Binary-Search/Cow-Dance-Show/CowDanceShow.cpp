#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
using vc = vector<lli>;

#define ff first
#define ss second
#define FOR(i, n) for(int i = 0; i<n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0; i--)

const int maxN = 2e5 + 5;
lli arr[maxN];
void printSet(multiset<lli>s)
{
    for(auto x: s)
    {
        cout<<x<<" ";
    }
    cout<<'\n';
}
bool poss(lli mid, lli Tmax, lli n)
{
    // cout<<"MID= "<<mid<<'\n';
    multiset<lli>s;
    FOR(i, mid)
    {
        s.insert(arr[i]);
    }
    lli curTime = 0;
    lli j = mid;
    while(!s.empty())
    {
        // printSet(s);
        curTime = *s.begin();
        s.erase(s.find(*s.begin()));
        if(j< n)
        {
            s.insert(curTime + arr[j]);
            j++;
        }
    }
    return curTime <= Tmax;

}
int main()
{
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    lli n;
    cin>>n;
    lli Tmax;
    cin>>Tmax;
    FOR(i , n)
    {
        cin>>arr[i];
    }
    // sort(arr, arr + n, greater<lli>());
    // FOR(i, n)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<'\n';
    lli left = 1;
    lli right = n;
    lli ans = n;
    while(left <= right)
    {
        lli mid = left + (right - left)/2;
        if(poss(mid, Tmax,n))
        {
            ans = mid;
            right = mid-1;
        }
        else{
            left = mid + 1;
        }
    }
    cout<<ans<<'\n';
}
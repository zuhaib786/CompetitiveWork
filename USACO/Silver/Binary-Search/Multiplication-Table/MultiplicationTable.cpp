#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
using vc = vector<lli>;

#define ff first
#define ss second
#define FOR(i, n) for(int i = 0; i<n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0; i--)

const int maxN = 1e6 + 6;
bool Poss(lli mid, lli n)
{
    lli ct = 0;
    FOR(i, n)
    {
        int j = i + 1;
        ct += min(mid /j, n);
    }
    return ct >= (n* n + 1)/2;
}
int main()
{
    lli n;
    cin>>n;
    lli left = 1;
    lli right = n*n;
    lli ans = 1;
    while(left<=right)
    {
        lli mid = left + (right - left )/2;
        if(Poss(mid, n))
        {
            right = mid - 1;
            ans = mid;
        }
        else
        {
            left = mid + 1;
        }
    } 
    cout<<ans<<'\n';
}
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
#define FOR(i, n) for(int i = 0; i<n; i++)

const int maxN = 2e5 + 5;
lli arr[maxN];
int main()
{
    int n;
    cin>>n;
    FOR(i, n)
    {
        cin>>arr[i];
    }
    sort(arr, arr + n);
    lli med = arr[(n - 1)/2];
    lli ans = 0;
    FOR(i, n)
    {
        ans += abs(med - arr[i]);
    }
    cout<<ans<<'\n';
}
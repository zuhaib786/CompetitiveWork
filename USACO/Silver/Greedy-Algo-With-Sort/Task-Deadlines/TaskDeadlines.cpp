#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
#define ff first
#define ss second

#define FOR(i,n) for(int i =0; i<n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0; i--)
#define all(x) begin(x), end(x)
#define xarr(x, n) x, x + n 

const int maxN = 2e5 +5;
pii arr[maxN];
int main()
{
    int n;
    cin>>n;
    FOR(i, n)
    {
        cin>>arr[i].ff>>arr[i].ss;
    }
    sort(xarr(arr, n));
    lli negCost = 0;
    lli posVal = 0;
    FOR(i,n)
    {
        // cout<<arr[i].ff<<" "<<arr[i].ss<<'\n';
        negCost += (n - i)*arr[i].ff;
        posVal += arr[i].ss;
    }
    cout<<posVal - negCost<<'\n';
}
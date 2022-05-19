#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;

#define ff first
#define ss second
#define FOR(i, n) for(int i = 0; i < n; i++)
#define ROF(i, n) for(int i = n - 1 ; i  >= 0; i--)

#define all(x) begin(x) , end(x)
#define xarr(x, n) x , x + n

const int maxN = 2e5 + 5;
pii arr[maxN];
int main()
{
    lli n, k;
    cin>>n>>k;
    FOR(i, n)
    {
        cin>>arr[i].ss>>arr[i].ff;
        arr[i].ff--;
    }
    sort(arr, arr + n);
    multiset<lli>s;
    FOR(i, k)
    {
        s.insert(0);
    }
    int ct = 0;
    FOR(i, n)
    {
        auto it = s.lower_bound(arr[i].ss);
        if(it == s.begin())
        continue;
        it--;
        s.erase(it);
        ct++;
        s.insert(arr[i].ff);
    }
    cout<<ct<<'\n';
}
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
#define ff first
#define ss second
#define FOR(i, n) for(int i = 0; i<n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0 ; i--)
const int maxN = 2e5 + 5;
lli arr[maxN];
int main()
{
    lli n,x;
    cin>>x>>n;
    FOR(i, n)
    {
        cin>>arr[i];
    }
    set<lli>s;
    multiset<lli>dis;
    s.insert(0);
    s.insert(x);
    dis.insert(x - 0);
    FOR(i, n)
    {
        auto it = s.lower_bound(arr[i]);
        assert(it != s.end() && it !=s.begin());
        lli ul = *it;
        it--;
        lli l = *it;
        dis.erase(dis.find(ul - l));
        s.insert(arr[i]);
        dis.insert(arr[i] - l);
        dis.insert(ul - arr[i]);
        cout<<*dis.rbegin()<<" ";
    }
    cout<<'\n';
}
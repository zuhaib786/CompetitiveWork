#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
using vc = vector<lli>;
#define ff first
#define ss second
#define FOR(i,n) for(int i = 0; i< n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0; i--)

const int maxN = 1e5 + 5;
pii arr[maxN];
lli dp[maxN + 1];
void setIO(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
struct query
{
    int s, d, i;
}Q[maxN];
bool comp(const query & q1 , const query & q2)
{
    return q1.s > q2.s;
}
int main()
{
    //Good question
    setIO("snowboots");
    int n, b;
    cin>>n>>b;
    FOR(i, n)
    {
        cin>>arr[i].ff;
        arr[i].ss = i;
    }
    sort(arr, arr + n, greater<pii>());
    multiset<int>lengths;
    set<int>s;
    for(int i = 0; i<n; i++)
    {
        s.insert(i);
    }
    for(auto it = s.begin(); next(it)!=s.end(); it++)
    {
        lengths.insert(*next(it) - *it);
    }
    FOR(i, b)
    {
        cin>>Q[i].s>>Q[i].d;
        Q[i].i = i;
    }
    int j = 0;
    sort(Q, Q + b, comp);
    FOR(i, b)
    {
        while(j< n && arr[j].ff > Q[i].s)
        {
            

            auto it = s.find(arr[j].ss);
            int a = *it;
            int b = *next(it);
            int c  = *prev(it);
            s.erase(it);
            assert(lengths.find(b - a)!=lengths.end());
            lengths.erase(lengths.find(b - a));
            assert(lengths.find(a - c)!=lengths.end());
            lengths.erase(lengths.find(a - c));
            lengths.insert( b - c);
            j++;
        }
        dp[Q[i].i] = (*lengths.rbegin() <= Q[i].d);
    }
    FOR(i, b)
    {
        cout<<dp[i]<<'\n';
    }
    

}
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
using vc = vector<lli>;
#define FOR(i, n) for(int i = 0 ; i< n; i++)

const int maxN = 2e5 + 5;
lli arr[maxN];
lli order[maxN];
void setIO(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
int main()
{
    setIO("highcard");
    int n;
    cin>>n;
    memset(arr, 0 , sizeof(arr));
    FOR(i, n)
    {
        int k;
        cin>>k;
        arr[k] = 1;
        order[i] = k;
    }
    set<int>s;
    FOR(i, 2*n)
    {
        if(arr[i + 1])
        {
            continue;
        }
        s.insert(i + 1);
    }
    lli ct =0;
    sort(order, order + n);
    FOR(i, n)
    {
        auto it = s.lower_bound(order[i]);
        if(it != s.end())
        {
            ct++;
            s.erase(s.find(*it));
        }
    }
    cout<<ct<<'\n';

}
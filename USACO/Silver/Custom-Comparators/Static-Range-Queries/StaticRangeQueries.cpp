#include <bits/stdc++.h>

using namespace std;
using lli = long long int;
const int maxN = 1e5 + 4;
lli arr[4*maxN];
lli ps[4*maxN];

struct  event
{
    int l , r, v;
};
struct query
{
    int l, r;
}Q[maxN];
event events[maxN];
int main(){
    int n, q;
    cin>>n>>q;
    map<lli, lli>m;
    map<lli, lli>rev;
    memset(arr, 0, sizeof(arr));
    for(int i = 0 ; i < n; i++)
    {
        cin>>events[i].l>>events[i].r>>events[i].v;
        // events[i].r--;
        m[events[i].l];
        m[events[i].r];
    }
    for(int i = 0; i<q; i++)
    {
        cin>>Q[i].l>>Q[i].r;
        Q[i].r--;
        Q[i].l--;
        m[Q[i].l];
        m[Q[i].r];
    }
    int cnt = 0;
    for(auto x: m)
    {
        // cout<<x.first<<" ";
        m[x.first] = cnt;
        cnt++;
    }
    // cout<<'\n';
    // m[-1] = -1;
    for(auto x: m)
    {
        rev[x.second] = x.first;
    }
    
    for(int i = 0 ; i<n; i++)
    {
        int lidx = m[events[i].l];
        int ridx = m[events[i].r];
        // ridx++;
        arr[lidx] += events[i].v;
        arr[ridx] += -events[i].v;
    }
    memset(ps, 0,sizeof(ps));
    lli curSum = 0;
    for(int i = 0; i<cnt; i++)
    {
        curSum += arr[i];
        arr[i] = curSum;
    }
    // for(int i = 0; i<cnt; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<'\n';
    for(int i = 0 ; i < cnt; i++)
    {
        if(i == 0)
        {
            ps[i] = arr[i];
            continue;
        }
        ps[i] = ps[i - 1] + (rev[i] - rev[i - 1] - 1)*arr[i - 1] + arr[i];
    }
    // for(int i = 0 ; i<cnt; i++)
    // {
    //     cout<<ps[i + 1]<<" ";
    // }
    // cout<<'\n';
    for(int i = 0; i<q; i++)
    {
        int l = Q[i].l, r = Q[i].r;
        l = m[Q[i].l];
        r = m[Q[i].r];
        // r++;
        cout<<ps[r] - ps[l]<<'\n';
    }
    
    return 0;
}

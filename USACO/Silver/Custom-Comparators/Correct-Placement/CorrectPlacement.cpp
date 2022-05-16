#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<pair<lli,lli>, lli>;
const int maxN = 2e5 + 5;
pii arr[maxN];
pii rev[maxN];
lli ans[maxN];
#define ff first
#define ss second
struct rect
{
    lli l, r,i;
};

void solve()
{
    int n;
    cin>>n;
    memset(ans, -1, sizeof(ans));
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i].ff.ff>>arr[i].ff.ss;
        arr[i].ss = i;
        rev[i] = {{arr[i].ff.ss, arr[i].ff.ff}, arr[i].ss};
    }
    sort(arr, arr + n);
    sort(rev, rev + n);
    int j = 0;
    set<pii>s;
    for(int i = 0; i<n; i++)
    {
        while(j < n && arr[j].ff.ff < arr[i].ff.ff)
        {
            s.insert({{arr[j].ff.ss, arr[j].ff.ff}, arr[j].ss});
            j++;
        }
        if(s.size() == 0)
        {
            continue;
        }
        pii p = *s.begin();
        // cout<<p.ff.ff<<" "<<p.ff.ss<<" "<<arr[i].ff.ff<<" "<<arr[i].ff.ss<<'\n';
        if(p.ff.ff < arr[i].ff.ss)
        {
            ans[arr[i].ss] = p.ss;
        }
    }
    s = set<pii>();
    j = 0;
    for(int i = 0; i<n; i++)
    {
        while(j < n && rev[j].ff.ff < arr[i].ff.ff)
        {

            s.insert({{rev[j].ff.ss, rev[j].ff.ff}, rev[j].ss});
            j ++ ;
        }
        // cout<<s.size()<<" ";
        if(s.size() == 0)
        {
            continue;
        }
        pii p = *s.begin();
        // cout<<p.ff.ff<<" "<<p.ff.ss<<" "<<arr[i].ff.ff<<" "<<arr[i].ff.ss<<'\n';
        if(p.ff.ff < arr[i].ff.ss)
        {
            ans[arr[i].ss] = p.ss;
        }
    }
    for(int i =0 ; i<n; i++)
    {
        if(ans[i] == -1)
        {
            cout<<ans[i]<<" ";
        }
        else
        {
            cout<<ans[i] + 1<<' ';
        }
    }
    cout<<'\n';

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
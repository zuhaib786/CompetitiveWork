#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
using vc = vector<int>;
#define ff first
#define ss second
#define FOR(i,n) for(int i = 0; i<n; i++)
#define ROF(i,n) for(int i = n - 1; i>=0; i--)
const int maxN = 2e5 + 5;
lli arr[maxN];
// lli save[maxN];
void solve()
{
   int n,k;
   cin>>n>>k;
   set<int>s;
   FOR(i, n + 1)
   {
       s.insert(i);
   }
   set<lli>sp;
   map<lli, lli>m;
   map<lli, lli>rev;
   FOR(i, n)
   {
       cin>>arr[i];
       sp.insert(arr[i]);
       m[arr[i]]++;
       if(s.find(arr[i])!=s.end())
       {
           s.erase(s.find(arr[i]));
       }
   }
   for(auto x: m)
   {
       rev[x.second]++;
   }
   FOR(i, k)
   {
       
       lli mex = *s.begin();
       if(sp.size() == mex)
       {
           cout<<0<<'\n';
           return;
       }
       while(sp.size() != 0 && *sp.begin() < mex)
       {
           rev[m[*sp.begin()]]--;
           if(rev[m[*sp.begin()]] ==0)  rev.erase(*sp.begin());
           m.erase(m.find(*sp.begin()));
           sp.erase(sp.find(*sp.begin()));
       }
       lli key = (*rev.begin()).first;
       if(key == 1)
       {
           s.erase(mex);
           rev[key]--;
           if(rev[key] == 0)
           {
               rev.erase(key);
           }
       }


   }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
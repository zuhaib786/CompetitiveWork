#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
using vc = vector<lli>;

#define ff first
#define ss second


#define FOR(i, n) for(int i= 0; i<n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0; i--)

const int maxN = 2e4 + 4;
int arr[maxN];
pii brr[maxN];

int main()
{
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);

    int c,n;
    cin>>c>>n;
    multiset<lli>s;
    FOR(i, c)
    {
        int k;
        cin>>k;
        s.insert(k);
    }
    sort(arr, arr + c);
    FOR(i, n)
    {
        cin>>brr[i].ff>>brr[i].ss;
    }
    sort(brr, brr + n, [&](pii a , pii b)
    {
        return a.second < b.second;
    });
   int i = 0; 
   int j = 0;
   lli cnt = 0;
   while(j < n)
   {
       auto it = s.lower_bound(brr[j].ff);
       if(it != s.end() && (*it) <= brr[j].ss)
       {
           s.erase(it);
           cnt++;
       }
       j++;
   }
   cout<<cnt<<'\n';
}
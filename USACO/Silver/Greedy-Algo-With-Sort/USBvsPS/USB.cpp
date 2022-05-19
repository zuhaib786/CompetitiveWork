#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
using vc = vector<lli>;

#define ff first
#define ss second

#define FOR(i, n) for(int i = 0; i<n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0; i--)

const int maxN = 3e5 + 5;
pii arr[maxN];
int type[maxN];
int main()
{
    lli a, b, c;
    cin>>a>>b>>c;
    int n;
    cin>>n;
    FOR(i, n)
    {
        cin>>arr[i].ff;
        string k;   
        cin>>k;
        if(k == "USB")
        {
            type[i] = 0;
        }
        else
        {
            type[i] = 1;
        }
        arr[i].ss = i;
    }
    sort(arr, arr + n);
    lli cost = 0;
    lli cnt = 0;
    for(int i = 0; i<n; i++)
    {
        if(type[arr[i].ss] == 0)
        {
            if(a!=0)
            {
                cost += arr[i].ff;
                cnt++;
                a--;
            }
            else if (c!=0)
            {
                cost += arr[i].ff;
                cnt++;
                c--;
            }
        }
        else
        {
            if(b!=0)
            {
                cost += arr[i].ff;
                cnt++;
                b--;
            }
            else if(c!=0)
            {
                cost += arr[i].ff;
                cnt++;
                c--;
            }
        }
    }
    cout<<cnt<<" "<<cost<<'\n';
}
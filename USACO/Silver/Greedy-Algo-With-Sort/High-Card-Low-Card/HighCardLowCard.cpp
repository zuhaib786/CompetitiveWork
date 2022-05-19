#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
const int maxN = 6e4 + 5;

#define FOR(i, n) for(int i = 0; i<n; i++)

int n;
#define all(x) x, x + n
lli brr[maxN];
lli crr[maxN];
lli arr[2*maxN];

int main()
{
    // int n;
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    cin>>n;
    memset(arr, 0,sizeof(arr));
    set<lli>s;
    int ct = 0;
    FOR(i, n)
    {
        if(i<n/2)
        {
            cin>>brr[i];
            arr[brr[i]] = 1;
        }
        else
        {
            cin>>crr[i- n/2];
            arr[crr[i - n/2]] =1;
        }
    }
    FOR(i, 2*n)
    {
        if(arr[i  + 1])
        {
            continue;
        }
        else
        {
            s.insert(i + 1);
        }
    }
    // FOR(i, n/2)
    // {
    //     cout<<brr[i]<<" ";
    // }
    // cout<<'\n';
    // FOR(i, n/2)
    // {
    //     cout<<crr[i]<<" ";
    // }
    // cout<<'\n';
    sort(brr, brr + n/2, greater<lli>());
    sort(crr , crr + n/2);
    FOR(i, n/2)
    {
        if(*s.rbegin()>brr[i])
        {
            s.erase(s.find(*s.rbegin()));
            ct++;
        }
    }
    FOR(i, n/2)
    {
        if(crr[i] < *s.begin())
        continue;
        s.erase(s.find(*s.begin()));
        ct++;

    }
    cout<<ct<<'\n';
   
}
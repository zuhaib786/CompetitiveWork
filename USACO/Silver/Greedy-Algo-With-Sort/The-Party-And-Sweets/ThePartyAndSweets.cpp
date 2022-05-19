#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
const int maxN = 1e5 + 5;

#define FOR(i, n) for(int i = 0; i<n; i++)

lli arr[maxN];
lli brr[maxN];
int main()
{
    int n,m;
    cin>>n>>m;
    lli mx = INT_MIN;
    lli sm = 0;
    FOR(i, n)
    {
        cin>>brr[i];
        mx = max(brr[i], mx);
        sm += brr[i];
    }
    FOR(i, m)
    {
        cin>>arr[i];
    }
    if(n == 1 && m == 1)
    {
        if(brr[0]!=arr[0])
        {
            cout<<-1<<'\n';
        }
        else
        {
            cout<<arr[0]<<'\n';
        }
    }
    else if (m == 1)
    {
        if(mx > arr[0])
        {
            cout<< - 1<<'\n' ;
        }
        else
        {
            cout<<sm + (arr[0] - mx)<<'\n';
        }
    }
    else if (n == 1)
    {
        bool poss = false;
        lli tot = 0;
        FOR(i, m)
        {
            poss = poss || (arr[i] ==  mx);
            if(arr[i] < mx)
            {
                poss = false;
                break;
            }
            tot += (sm + arr[i] - mx);
        }
        if(!poss)
        {
            cout<<-1<<'\n';
            return 0;
        }
        cout<<tot<<'\n';
    }
    else
    {
        lli tot = 0;
        bool poss = true;
        lli smx = -1;
        nth_element(brr, brr + n - 2, brr + n);
        lli mnDif = INT_MAX;
        FOR(i, m)
        {
            if(arr[i] < mx)
            {
                poss = false;
                break;
            }
            mnDif = min(mnDif, arr[i] - mx);
            tot += (sm + arr[i] - mx);
        }
        if(!poss)
        {
            cout<<-1<<'\n';
            return  0;
        }
        if(mnDif != 0)
        {
            tot += mx - brr[n - 2];
        }
        cout<<tot<<'\n';
    }


}
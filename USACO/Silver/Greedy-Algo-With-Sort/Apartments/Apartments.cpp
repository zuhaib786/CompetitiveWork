#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
using vc = vector<lli>;

#define ff first
#define ss second

#define FOR(i, n) for(int i = 0; i<n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0; i--)

const int maxN = 2e5 + 5;
pii arr[3*maxN];
int main()
{
    lli n,m,k;
    cin>>n>>m>>k;
    FOR(i, n)
    {
        lli a ;
        cin>>a;
        arr[2*i] = {a - k,  -1};    // FOR(i, 2*n + m)
    // {
    //     cout<<arr[i].ff<<" "<<arr[i].ss<<'\n';
    // }
        arr[2*i + 1]  = {a + k, 1};
    }
    FOR(i, m)
    {
        int a;
        cin>>a;
        arr[i + 2*n] = {a, 0};
    }
    int cnt = 0;
    sort(arr, arr + 2*n + m);
    int waiter = 0;
    int used = 0;
    FOR(i, 2*n + m)
    {
        if(arr[i].ss <0)
        {
            waiter++;
        }
        else if (arr[i].ss == 0)
        {
            cnt += waiter!=0;
            used += waiter !=0;
            waiter = max(0, waiter - 1);
        }
        else
        {
            if(used == 0)
            waiter--;
            else
            used--;
        }
    }
    cout<<cnt<<'\n';
}
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

void solve()
{
    int n,  q;
    cin>>n>>q;
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort(arr , arr + n);
    lli ps[n + 1];
    ps[0] = 0;
    for(int i = 0; i<n; i++)
    {
        ps[i+1] = ps[i] + arr[n - 1 - i];
    }
    while(q--)
    {
        lli x;
        cin >> x;
        if(x > ps[n])
        {
            cout<<-1<<'\n';
            continue;
        }
        int id = lower_bound(ps, ps + n + 1, x) - ps;
        cout<<id<<'\n';

    }

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

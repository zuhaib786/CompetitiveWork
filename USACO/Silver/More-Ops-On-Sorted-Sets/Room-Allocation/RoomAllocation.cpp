#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
#define ff first
#define ss second
#define FOR(i, n) for(int i = 0; i<n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0 ; i--)
const int maxN = 2e5 + 5;
pii arr[2*maxN];
int ans[maxN];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    set<int>s;
    int n;
    cin>>n;
    FOR(i,n)
    {
        cin>>arr[2*i].first >> arr[2*i+1].first;
        arr[2*i].second = i+1;
        arr[2*i+1].second = -i-1;
        arr[2*i+1].first++;
    }
    sort(arr, arr+2*n);
    int cur = 1;
    FOR(i,2*n)
    {
        if(arr[i].second < 0)
        {
            // departure
            s.insert(ans[-arr[i].second -1]);
        }
        else
        {
            // arrival
            if(s.size() == 0)
            {
                ans[arr[i].second - 1] = cur;
                cur++;
            }
            else
            {
                ans[arr[i].second - 1] = *s.begin();
                s.erase(s.find(*s.begin()));
            }
        }
    }
    cout<<cur-1<<'\n';
    FOR(i,n)
    {
        cout<<ans[i]<<" ";
    }
    cout<<'\n';
}
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<int, int>;
const int maxN = 1e2 + 2;
void setIO(string name)
{
    cin.tie(0)->sync_with_stdio(0);
    freopen((name + ".in").c_str() , "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
pii arr[maxN];  
int main()
{
    setIO("cowqueue");
    int n;
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr, arr + n);
    // set<pii>s;
    int i = 0;
    int cur_time = 0;
    for(int i = 0; i<n; i++)
    {
        cur_time = max(cur_time, arr[i].first);
        cur_time += arr[i].second;
    }
    cout<<cur_time<<'\n';

}
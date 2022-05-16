#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
const int maxN = 1e5 + 5;
void setIO(string name = "")
{
    if(name.size() == 0)
        return;
    cin.tie(0)->sync_with_stdio(0);
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
pii arr[2*maxN];
lli singleDuty[maxN];
int main()
{
    setIO("lifeguards");
    int n;
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        cin>>arr[2*i].first>>arr[2*i + 1].first;
        arr[2*i].second = i + 1;
        arr[2*i + 1].second = -i -1 ;
    }
    memset(singleDuty, 0, sizeof(singleDuty));
    sort(arr, arr + 2*n);
    set<int>s;
    lli curTime = 0;
    lli totTime = 0;
    for(int i = 0; i<2*n; i++)
    {
        if(s.size() != 0)
        {
            // cout<<"YES\n";
            totTime += (arr[i].first) - curTime;
        }
        if(s.size() == 1)
        {
            singleDuty[*s.begin() - 1] += arr[i].first - curTime;
        }
        if(arr[i].second < 0)
        {
            assert(s.size() > 0);
            assert(s.find(abs(arr[i].second) )!= s.end());
            s.erase(abs(arr[i].second));
        }
        else
        {
            s.insert(arr[i].second);
        }
        curTime = arr[i].first;
    }
    // cout<<n<<'\n';
    // // for(int i = 0; i < 2*n; i++)
    // // {
    // //     cout<<arr[i].first<<" ";
    // // }
    // cout<<'\n';
    lli ans = INT_MIN;
    for(int i = 0; i<n; i++)
    {
        ans = max(ans, totTime - singleDuty[i]);
    }
    cout<<ans<<'\n';
}

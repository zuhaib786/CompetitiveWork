//Sleep
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
void setIO(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
int n;
lli arr[100005];
int isPoss(int sm)
{
    int cur = 0;
    int length = 0;
    int cnt = 0;
    for(int i = 0; i<n; i++)
    {
        if(cur + arr[i] > sm)
        {
            return INT_MAX;
        }
        cur += arr[i];
        length++;
        if(cur == sm)
        {
            // cnt++;
            cnt += length - 1;
            length = 0;
            cur = 0;
        }
    }
    return cnt;
}
int main()
{
    // setIO("sleep");
    int t;
    cin>>t;
    while(t--)
    {
        
        cin>>n;
        lli sum = 0;
        for(int i = 0; i<n; i++)
        {
            cin>>arr[i];
            sum += arr[i];
        }
        if(sum == 0)
        {
            cout<<0<<'\n';
            continue;
        }
        int sq = sqrt(sum);
        int mx = INT_MAX;
        for(int i = 1; i<=sum; i++)
        {
            if(sum%i == 0)
            {
                int m1 = isPoss(sum/i);
                int m2 = isPoss(i);
                mx = min({mx, m1, m2});
            }
        }
        cout<<mx<<'\n';
    }
}
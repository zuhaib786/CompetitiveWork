#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
void setIO(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
int main()
{
    setIO("div7");
    int n;
    cin>>n;
    int arr[n];
    // cin>>arr[i];
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    map<int, int>m;
    int curSum = 0;
    m[0] = -1;
    int maxLen = 0;
    for(int i = 0; i<n; i++)
    {
        curSum += arr[i]; 
        curSum %= 7;
        if(m.count(curSum))
        {
            // cout<<i<<" "<<curSum<<" "<<m[curSum]<<'\n';
            maxLen = max(maxLen, i - m[curSum]);
        }
        else
        {

            m[curSum] = i;
        }
    }
    cout<<maxLen<<'\n';
}
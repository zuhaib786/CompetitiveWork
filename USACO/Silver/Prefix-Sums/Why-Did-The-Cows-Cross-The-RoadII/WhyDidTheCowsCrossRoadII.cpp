#include<bits/stdc++.h>
using namespace std;
using lli  = long long int;
void setIO(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
int main()
{
    setIO("maxcross");
    int n,k,b;
    cin>>n>>k>>b;
    int arr[n + 1];
    memset(arr, 0, sizeof(arr));
    for(int i = 0; i<b; i++)
    {
        int w;
        cin>>w;
        arr[w] = 1;
    }
    // for(int i = 0; i< n + 1; i++)
    // {
    //     cout<<arr[i]<< " ";
    // }
    // cout<<'\n';
    int sum = 0;
    for(int i = 0; i<k ; i++)
    {
        sum += arr[i];
    }
    int mn = INT_MAX;
    for(int i = k ; i<n + 1; i++)
    {
        sum += arr[i];
        // cout<<sum<<'\n';
        mn = min(mn, sum);
        sum -= arr[i - k + 1];
    }
    cout<<mn<<'\n';
} 
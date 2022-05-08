#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
pii arr[200005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n,x;
    cin>>n>>x;
    for(lli i = 0; i<n; i++)
    {
        cin>>arr[i].first;
        arr[i].second = i;
    }
    sort(arr, arr+n);
    int i = 0, j = n-1;
    while(i<j)
    {
        // cout<<i<<" "<<j<<endl;
        lli k = arr[i].first + arr[j].first;
        if(k == x)
        {
            cout<<arr[i].second+1<<" "<<arr[j].second+1<<'\n';
            return 0;
        }
        else if (k<x)
        {
            i++;
        }
        else
        j--;
    }
    cout<<"IMPOSSIBLE\n";
}
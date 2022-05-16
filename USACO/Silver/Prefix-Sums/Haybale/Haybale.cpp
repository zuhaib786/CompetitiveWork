#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int main()
{
    int n, k;
    cin>>n>>k;
    lli arr[ n  + 1];
    memset(arr, 0, sizeof(arr));
    for(int i = 0; i<k; i++)
    {
        int a, b;
        cin>>a>>b;
        a--;
        arr[a] += 1;
        arr[b] -=1;
    }
    lli curSum =0;
    for(int i = 0; i<n; i++)
    {
        curSum += arr[i];
        arr[i] = curSum;
    }
    sort(arr, arr + n);
    cout<<arr[n/2]<<'\n';


}
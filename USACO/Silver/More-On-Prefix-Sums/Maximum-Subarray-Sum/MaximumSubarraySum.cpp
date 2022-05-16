#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
lli arr[200005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    } 
    lli maxima = *max_element(arr, arr+n);
    if (maxima<0)
    {
        cout<<maxima<<endl;
        return 0;
    }
    
    lli cur_sum  = 0;
    for(int i = 0; i<n; i++)
    {
        if(cur_sum + arr[i]<0)
        {
            cur_sum =0;
        }
        else
        {
            cur_sum+=arr[i];
        }
        maxima = max(maxima, cur_sum);
    }
    cout<<maxima<<endl;
}
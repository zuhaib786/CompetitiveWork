#include<bits/stdc++.h>
using namespace std; 
using lli = long long int;
using pii = pair<lli, lli>;
lli arr[200005];
const lli MAX = 1e17;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    lli n, t;
    cin>>n>>t;
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    lli minTime = 1;
    lli maxTime = (*min_element(arr, arr+n))*t;
    lli ans = maxTime;
    while(minTime<=maxTime)
    {
        lli midTime = minTime + (maxTime -minTime)/2;
        lli amt = 0;
        for(int i = 0; i<n; i++)
        {
            amt+=midTime/arr[i];
        }
        if(amt>=t)
        {
            ans = min(ans, midTime);
            maxTime = midTime-1;
        }
        else
        {
            minTime = midTime +1;
        }
        
    }
    cout<<ans<<endl;
    
    
}
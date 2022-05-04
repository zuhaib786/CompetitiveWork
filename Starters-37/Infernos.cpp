#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        lli n, x;
        cin>>n>>x;
        lli arr[n];
        lli maxima = INT_MIN;
        lli hc = 0;
        for(int i = 0; i<n; i++)
        {
            cin>>arr[i];
            hc += arr[i]/x + (arr[i]%x !=0);
            maxima = max(maxima, arr[i]);
        }
        hc = min(maxima,hc );
        cout<<hc<<'\n';
    }
}

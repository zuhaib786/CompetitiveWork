#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        lli sum = 0;
        for(int i = 0; i<n; i++)
        {
            lli k;
            cin>>k;
            sum += k;
        }
        if(sum %(n/2) == 0 && (sum/(n/2)%2 == 1))
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }

    }
    return 0;
}

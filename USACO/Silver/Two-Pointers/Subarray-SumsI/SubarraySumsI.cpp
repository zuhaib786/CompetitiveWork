#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
#define ff first
#define ss second
#define FOR(i, n, k) for(int i = 0; i<n; i+=k)
const int maxN = 2e5 + 5;
lli arr[maxN];
int main()
{
    int n;
    cin>>n;
    lli x;
    cin>>x;
    FOR(i, n, 1)
    {
        cin>>arr[i];
    }
    int i = 0;
    int j = 0;
    lli sum = 0;
    lli cnt = 0;
    int ctitr = 0;
    while(i< n && j<n)
    {
        assert(ctitr <= maxN);
        ctitr ++;
        sum += arr[j];
        if(sum == x)
        {
            cnt++;
        
        }
        else if (sum > x)
        {
            while(sum >x)
            {
                sum -= arr[i];
                i++;
            }
            if(sum == x)
            {
                cnt++;
            }
        }
        j++;
    }
    cout<<cnt<<'\n';

}
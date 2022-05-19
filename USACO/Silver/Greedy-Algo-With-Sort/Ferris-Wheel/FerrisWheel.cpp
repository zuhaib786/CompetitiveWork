#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;

#define ff first
#define ss second

#define FOR(i,n) for(int i = 0; i<n; i++)
#define ROF(i,n) for(int i = n - 1; i>=0; i--)

const int maxN = 2e5 + 5;
lli arr[maxN];
int main()
{
    lli n, x;
    cin>>n>>x;
    FOR(i, n)
    {
        cin>>arr[i];
    }
    sort(arr, arr + n);
    int i = 0; 
    int j = n - 1;
    lli cnt = 0;
    while(i<=j)
    {
        if(i == j)
        {
            cnt++;
            i++;
            j--;
        }
        else
        {
            if(arr[i] + arr[j] <= x)
            {
                cnt++;
                i++;
                j--;
            }
            else 
            {
                cnt++;
                j--;
            }
        }
    }
    cout<<cnt<<'\n';
}
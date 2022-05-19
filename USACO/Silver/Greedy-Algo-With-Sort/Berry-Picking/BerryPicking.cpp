#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
const int maxN = 1003;
lli arr[maxN];
int main()
{
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    int n,k;
    cin>>n>>k;
    assert(k%2 == 0);
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr + n, greater<lli>());
    
}
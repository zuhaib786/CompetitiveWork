#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int main()
{
    int n;
    cin>>n;
    lli arr[n];
    for(int i = 0 ; i<n; i++)
    {
        cin>>arr[i];
    }
    lli lt[n], rt[n];
    lt[0] = arr[0];
    rt[n - 1] = arr[n-1];
    for(int i = 1; i<n ; i++)
    {
        lt[i] = __gcd(lt[i - 1], arr[i]);
    }
    for(int i = n -2; i>=0; i--)
    {
        rt[i] = __gcd(rt[i + 1], arr[i]);
    }
    lli mx =1;
    for(int i = 0; i<n; i++)
    {
        if(i == 0)
        {
            mx = max(mx, rt[i + 1]);
        }
        else if ( i == n - 1)
        {
            mx = max(mx, lt[i -1]);
        }
        else
        {
            mx = max( mx, __gcd(lt[i - 1], rt[i + 1]));
        }
    }
    cout<<mx<<'\n';
}
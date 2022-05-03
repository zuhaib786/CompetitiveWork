#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int arr[200005];
int brr[200005];
bool solve(int idx, int n)
{
    if(idx == n)
        return true;
    if((n - idx)%2 == 0)
    {
        int a[2] = {arr[idx], arr[idx + 1]};
        int b[2] = {brr[idx], brr[idx + 1]};
        sort(a, a + 2);
        sort(b, b+2);
        bool xd = (a[0] == b[0]) && (a[1] == b[1]);
        if(xd)
        {
            return solve(idx + 2, n);
        }

        return false;
    }
    else
    {
        if(arr[idx] != brr[idx])
        {
            return false;
        }
        return solve( idx + 1, n);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i = 0; i< n; i++)
        {
            cin>>arr[i];
            brr[i] = arr[i];
        }
        sort(arr, arr + n);
        bool b = solve(0, n);
        if(b)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
}

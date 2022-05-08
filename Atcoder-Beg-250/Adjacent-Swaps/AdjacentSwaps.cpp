#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int main()
{
    int n, q;
    cin>>n>>q;
    map<int, int>m;
    for(int i =0; i<n; i++)
    {
        m[i] = i;
    }
    int arr[n];
    for(int i = 0; i<n;i++)
    {
        arr[i] = i;
    }
    if(n == 1)
    {
        cout<<1<<'\n';
        return 0;
    }
    while(q--)
    {
        int x;
        cin>>x;
        x--;
        int idx = m[x];
        if(idx == n - 1)
        {
            int val1 = arr[n-1];
            int val2 = arr[n-2];
            swap(arr[n-1], arr[n - 2]);
            m[val1] = n-2;
            m[val2] = n-1;
        }
        else
        {
            int val1 = arr[idx];
            int val2 = arr[idx + 1];
            swap(arr[idx], arr[idx + 1]);
            m[val1] = idx + 1;
            m[val2] = idx;
        }
    }
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i] + 1<<" ";
    }
    cout<<'\n';
}


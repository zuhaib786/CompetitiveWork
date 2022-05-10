#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
void setIO(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int main()
{
    setIO("taming");
    int n;
    cin>>n;
    int arr[n + 1];
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i + 1];
    }
    arr[0] = 0;
    for(int i = n ; i>0; i--)
    {
        if(arr[i]!=-1)
        {
            int val = arr[i];
            for(int j = i; j >= i - arr[i]; j--)
            {
                
                if(arr[j]!= -1 && arr[j]!=val)
                {
                    cout<<-1<<'\n';
                    return 0;
                }
                arr[j] = val;
                val--;
            }
        }
    }
    // for(int i = 1; i<n + 1; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<"\n";
    int mx = 0, mn = 0;
    arr[1] = 0;
    for(int i = 1; i< n+1; i++)
    {
        // c
        if(arr[i] == - 1|| arr[i] == 0)
            mx++;
        if(arr[i] == 0)
            mn++;
    }
    cout<<mn<<" "<<mx<<'\n';
}
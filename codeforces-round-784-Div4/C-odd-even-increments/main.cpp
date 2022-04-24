#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int arr[10000];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        bool poss = true;
        for(int i = 0; i< n; i++)
        {
            cin>>arr[i];
            arr[i]%=2;
        }
        for(int i = 0; i< n; i+=2)
        {
            if(arr[i] != arr[0])
            {
                poss = false;
            }
        }
        for(int i = 1; i< n; i+=2)
        {
            if(arr[i] != arr[1])
            {
                poss = false;
            }
        }
        if(poss)
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
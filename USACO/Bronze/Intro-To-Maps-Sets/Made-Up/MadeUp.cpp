#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int main()
{
    int n;
    cin>>n;
    map<int, int>m;
    for(int i = 0; i< n; i++)
    {
        int k;
        cin>>k;
        m[k]++;
    }
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    lli cnt =  0;
    for(int i = 0 ; i<n; i++)
    {
        int k;
        cin>>k;
        k--;
        cnt += m[arr[k]];
    }
    cout<<cnt<<'\n';
}
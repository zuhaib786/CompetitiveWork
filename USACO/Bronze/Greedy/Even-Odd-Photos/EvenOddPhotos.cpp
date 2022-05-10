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
    int n;
    cin>>n;
    int arr[2];
    memset(arr, 0, sizeof(arr));
    for(int i = 0; i<n; i++)
    {
        int k;
        cin>>k;
        arr[k%2]++;
    }
    // case of even < odd
    // Say 3e 4o
    // e o e o e o o--> Does not work// Need to merge e o (oo) o (ee) when diff is odd
    // Now say 3e 5o
    // e o e o e o (oo) 
    if(arr[0] > arr[1])
    {
        // 6e 3o -> e o e o e o (eee)
        cout<<2*arr[1] + 1<<'\n';
    }
    else if (arr[0] < arr[1])
    {
        int cnt= 2*arr[0];
        arr[1] -= arr[0];
        if(arr[1]%3 == 0)
        {
            cnt += 2*(arr[1]/3);
        }
        else if(arr[1]%3 == 1)
        {
            cnt += 2*(arr[1]/3) - 1;
        }
        else
        {
            cnt += 2*(arr[1]/3) + 1;
        }
        cout<<cnt<<'\n';
    
    }
    else
    {
        cout<<2*arr[0]<<'\n';
    }
}
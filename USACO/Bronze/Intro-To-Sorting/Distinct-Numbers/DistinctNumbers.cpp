#include<bits/stdc++.h>
using namespace std;
int arr[200005];
void setIO(string name = "")
{
    if(name.size() == 0)    return;
    freopen((name + ".in").c_str() , "r", stdin);
    freopen((name + ".out").c_str() , "w", stdout);
}
int main()
{
    // setIO("distinct");
    int n;
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+n);
    int cnt = 0;
    int prev = -1;
    for(int i = 0; i<n; i++)
    {
        cnt+=prev !=arr[i];
        prev = arr[i];
    }
    cout<<cnt<<'\n';
}
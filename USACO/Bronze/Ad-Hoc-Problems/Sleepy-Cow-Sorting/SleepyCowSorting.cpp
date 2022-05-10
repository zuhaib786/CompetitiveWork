#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
void setIO(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
void insert(int arr[], int n, int left, int right)
{
    assert(left <= n- 1 && right <= n- 1);
    int val = arr[left];
    for(int j = left; j<right; j++)
    {
        arr[j] = arr[j + 1];
    }
    arr[right] = val;
    return;
}
int main()
{
    setIO("sleepy");
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    int mxIdx = n - 1;
    for(int i = n - 1; i>0;i--)
    {
        if(arr[i - 1] < arr[i])
        {
            mxIdx = i - 1;
        }
        else
            break;
    }
    cout<<mxIdx<<'\n';


}
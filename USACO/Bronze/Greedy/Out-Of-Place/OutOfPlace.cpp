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
    setIO("outofplace");
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++)
    {
        cin>>arr[i];
    }
    vector<int>temp;
    int prev = -1;
    for(int i = 0; i<n; i++)
    {
        if(arr[i]!=prev)
        {
            temp.push_back(arr[i]);
            prev = arr[i];
        }
    }
    vector<int>v = temp;
    sort(v.begin(), v.end());
    int left = -1;
    for(int i = 0; i<temp.size(); i++)
    {
        if(v[i]!=temp[i])
        {
            left = i;
            break;
        }
    }
    int right = -1;
    for(int i = temp.size() - 1; i>=0; i--)
    {
        if(temp[i] != v[i])
        {
            right = i;
            break;
        }
    }
    if(left == -1)
    {
        cout<<0<<'\n';
    }
    else
    {
        cout<<(right - left)<<'\n';
    }

}
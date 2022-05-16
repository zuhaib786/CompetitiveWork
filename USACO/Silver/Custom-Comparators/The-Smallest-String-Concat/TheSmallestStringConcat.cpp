#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
bool comp(const string &s1, const string & s2)
{
    return (s1 + s2)< (s2 + s1);
}
const int maxN = 5e4 + 4;
string arr[maxN];
int main()
{
    int n;
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr + n, comp);
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i];
    }
    cout<<'\n';
    
}
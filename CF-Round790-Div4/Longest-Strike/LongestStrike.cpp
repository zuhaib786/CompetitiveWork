#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

void solve()
{
    int n, k;
    cin>>n>>k;
    map<int, int>m;
    for(int i = 0; i<n; i++)
    {
        int temp;
        cin>>temp;
        m[temp]++;
    }
    vector<int>v;
    for(auto x :m)
    {
        if(x.second>=k)
        {
            v.push_back(x.first);
        }
    }
    // for(auto x: v)
    // {
    //     cout<<x<<" ";
    // }
    // cout<<'\n';
    if(v.size() == 0)
    {
        cout<<-1<<'\n';
    }
    else
    {
        int l = v[0];
        int r = v[0];
        int lmx = v[0];
        int rmx = v[0];
        int mx = 0;
        for(int i = 1; i<v.size(); i++)
        {
            if(v[i] == r + 1)
            {
                r++;
            }
            else
            {
                l = v[i];
                r = v[i];
            }
            mx = max(mx, r - l);
            if(mx == r - l)
            {
                lmx = l;
                rmx = r;
            }
        }
        cout<<lmx<<" "<<rmx<<'\n';
    }


}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }   
}

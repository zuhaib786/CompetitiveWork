#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<lli, lli>m;
    int q;
    cin>>q;
    while(q--)
    {
        int type;
        cin>>type;
        if(type == 0)
        {
            lli k, v;
            cin>>k>>v;
            m[k] = v;
        }
        else
        {
            lli k;
            cin>>k;
            cout<<m[k]<<'\n';
        }
    }
}
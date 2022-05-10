#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
void solve()
{
    string s;
    cin>>s;
    int c1 = 0;
    int c2 = 0;
    for(int i = 0; i<3; i++)
    {
        c1 += s[i] - '0';
    }
    for(int i = 3; i<6; i++)
    {
        c2 += s[i] - '0';
    }
    if(c1 == c2)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
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

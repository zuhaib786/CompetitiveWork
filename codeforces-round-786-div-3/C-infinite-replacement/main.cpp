#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int arr[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        string b;
        cin>>s>>b;
        if(b == "a")
        {
            cout<<1<<'\n';
        }
        else if (b.find("a") != -1)
        {
            cout<<-1<<'\n';
        }
        else
        {
            lli ans = pow(2, s.size());
            cout<<ans<<'\n';
        }
    }
}

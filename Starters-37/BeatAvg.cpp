#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        lli n,m,x;
        cin>> n>>m>>x;
        if( m == x)
        {
            cout<<"0\n";
            continue;
        }
        cout<<(n * x) / (x + 1)<<'\n';
    }
}


#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int zercnt = 0;
        int onecnt =0;
        for(int i =0;i<n; i++)
        {
            int k;
            cin>>k;
            if(k == 0)
            {
                zercnt++;
            }
            else
            {
                onecnt++;
            }
        }
        if(zercnt <= onecnt)
        {
            cout<<1<<'\n';
        }
        else
        {
            cout<<"0\n";
        }
    }
    return 0;
}

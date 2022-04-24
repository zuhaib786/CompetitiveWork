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
        unordered_map<int, int>m;
        for(int i = 0; i< n; i++)
        {
            int k;
            cin>>k;
            m[k]++;
        }
        bool poss = false;
        for(auto x: m)
        {
            if(x.second >=3)
            {
                cout<<x.first<<'\n';
                poss = true;
                break;
            }
        }
        if(!poss)
        {
            cout<<-1<<'\n';
        }
    }
    return 0;
}
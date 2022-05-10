#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
lli score[2001];
set<lli>m;
int main()
{
    int k,n;
    cin>>k>>n;
    for(int i = 0; i < k; i++)
    {
        cin>>score[i];
    }
    lli onesc = -1;
    for(int i = 0; i < n; i++)
    {
        int l;
        cin>>l;
        onesc =l;
        m.insert(l);
    }
    // cout<<onesc<<'\n';
    set<lli>poss;
    int curSum = 0;
    for(int i = 0; i<k; i++)
    {
        set<lli>temp;
        // lli sc = onesc + score[i];
        curSum += score[i];
        lli atZ = onesc - curSum ;
        for(int j = 0; j<k; j++)
        {
            temp.insert(atZ + score[j]);
            atZ += score[j];
        }
        bool check = true;
        for(auto x: m)
        {
            if(temp.find(x) == temp.end())
            {
                check = false;
                break;
            }
        }
        // cout<<check<<'\n';
        if(check)
        {
            poss.insert(atZ);
        }
    }
    cout<<poss.size()<<'\n';
}
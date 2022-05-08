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
    set<lli>poss;
    for(int i = 0; i<k; i++)
    {
        set<lli>temp;
        lli sc = onesc;
        lli atZ = 0;
        for(int j = i; j>=0; j--)
        {
            sc = sc - score[j];
            if(j == 0)
                atZ = sc;
            temp.insert(sc);
        }
        sc = onesc;
        for(int j = i + 1; j< k; j++)
        {
            sc = sc + score[i];
            temp.insert(sc);
        }
        cout<<"At Zero "<<atZ<<'\n';
        for(auto x: temp)
        {
            cout<<x<<" "<<" ";
        }
        cout<<'\n';
        bool check = true;
        for(auto x: m)
        {
            if(temp.find(x) == temp.end())
            {
                check = false;
                break;
            }
        }
        cout<<check<<'\n';
        if(check)
        {
            poss.insert(atZ);
        }
    }
    cout<<poss.size()<<'\n';
}
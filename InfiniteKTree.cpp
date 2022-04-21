#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
lli parent(lli x, lli k)
{
    return x/k;
}
int main()
{
    int k,q;
    cin>>k>>q;
    map<pii, lli> m;
    
    for(int i = 0; i < q; i++)
    {
        lli dis = 0;
        lli t, u, v;
        cin>>t>>u>>v;
        // cout<<t<<" "<<u<<" "<<v<<endl;
        if(t == 1)
        {   
            while(u != v)
            {
                if(u > v)
                {
                    if(m.count({parent(u, k), u}))
                    {
                        dis += m[{parent(u, k), u}] + 1;
                    } 
                    else
                    {
                        dis++;
                    }
                    u = parent(u, k);
                }
                else if (v > u)
                {
                    if(m.count({parent(v, k), v}))
                    {
                        dis += m[{parent(v, k), v}] + 1;
                    } 
                    else
                    {
                        dis++;
                    }
                    v = parent(v, k);
                }
            }
            cout<<dis<<"\n";
        }
        else
        {
            lli w;
            cin>>w;
            while(u != v)
            {
                if(u > v)
                {
                    m[{parent(u, k), u}] += w;
                    u = parent(u, k);
                }
                else if (v > u)
                {
                    m[{parent(v, k), v}] += w;
                    v = parent(v, k);
                }
            }
        }
    }

}
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
multiset<lli>s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i = 0; i<n; i++)
    {
        lli k;
        cin>>k;
        s.insert(k);
    }
    for(int i = 0; i<m; i++)
    {
        lli k;
        cin>>k;
        if(s.size() == 0)
        {
            cout<<"-1\n";
            continue;
        }
        auto it = s.lower_bound(k);
        
        if(it!=s.end() && *it <= k)
        {
            cout<<*it<<"\n";
            s.erase(s.find(*it));
            
        }
        else
        {
            if(it == s.begin())
            {
                cout<<-1<<"\n";
                continue;
            }
            it--;
            cout<<*it<<"\n";
            s.erase(s.find(*it));
        }
    }
    cout<<endl;
    
}
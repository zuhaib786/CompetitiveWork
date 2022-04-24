#include <bits/stdc++.h>
using lli = long long int;
using namespace std;

// 💖 Hi, thanks for using ICIE! 💖
// 🔧 To use a custom code template, press Ctrl+Shift+P and select "ICIE Template configure" from the list 🔧
// 📝 If you spot any bugs or miss any features, create an issue at https://github.com/pustaczek/icie/issues 📝

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int adj[n + 1];
        memset(adj, 0 ,sizeof(adj));
        for(int i = 0; i< n - 1; i++)
        {
            int k;
            cin>>k;
            k--;
            // adj[i+1].push_back(k);
            adj[k]++;
        }
        adj[n] = 1 ;
        sort(adj, adj + n + 1);
        int idx = 0;
        while(idx < n + 1 && adj[idx] == 0)
            idx++;
        int tot = n + 1 - idx;
        multiset<int>s;
        for(int i = idx ; i < n + 1; i++)
        {
            // cout<<adj[i] -  ( i - idx + 1)   <<" ";
            if(adj[i] - ( i - idx + 1) > 0)
                s.insert(adj[i] - ( i - idx + 1));
        }
        // cout<<endl;
        while(s.size())
        {
            multiset<int>ms;
            auto it = *s.rbegin();
            s.erase(s.find(it));
            if(it - 1  > 0 )
            {
                s.insert(it - 1);
            }
            for(auto x: s)
            {
                if(x - 1 > 0)
                {
                    ms.insert(x - 1);
                }
            }
            s = ms;
            tot++;
        }
        cout<<tot<<endl;

    }
}
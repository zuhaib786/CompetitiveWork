#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
void setIO(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
int main()
{
    setIO("milkorder");
    int n,m,kk;
    cin>>n>>m>>kk;
    int arr[n];
    bool contains = false;
    memset(arr, 0,sizeof(arr));
    int order[m];
    for(int i = 0 ; i<m; i++)
    {
        cin>>order[i];
        contains = (order[i] == 1)||contains;
    }
    map<int, int>mp;
    for(int i = 0; i<kk; i++)
    {
        int p,c;
        cin>>c>>p;
        mp[c] = p - 1;
        arr[p - 1] = c;
    }
    
    if(mp.count(1))
    {
        cout<<mp[1] + 1<<'\n';
        return 0;
    }
    if(contains)
    {
        // int pos = 0;
        int cur = 0;
        for(int i = 0; i<m; i++)
        {
            if(mp.count(order[i]))
            {
                cur = mp[order[i]];
            }
            else
            {
                while(arr[cur]!=0) cur++;
                arr[cur] =  order[i];
            }
            cur++;
            if(order[i] == 1)
            {
                cout<<cur<<'\n';
                return 0;
            }
        }
        return 0 ;
    }
    // cout<<"WHY THE FUCK\n";
    // for(int i = 0; i<n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<'\n';
    int prev =  - 1;
    set<int>added;
    for(int j = 0; j<m; j++)
    {
        if(mp.count(order[j]))
        {
            // cout<<j<<'\n';
            added.insert(order[j]);
            int idx = mp[order[j]];
            // idx--;
            for(int k = j - 1; k>prev; k--)
            {
                added.insert(order[k]);
                while(arr[idx]!=0)
                    idx--;
                mp[order[k]] = idx;
                arr[idx] = order[k];
                idx--;
            }
            // cout
            prev = j;
        }
    }
    // for(int i = 0; i<n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<'\n';
    int k  = n-1;
    for(int i = m - 1; i>=0; i--)
    {
        if(added.count(order[i]))
        {
            k = mp[order[i]];
            continue;
        }
        while(arr[k]!=0)
        {
            k--;
        }
        arr[k] = order[i];
    }
    // for(int i = 0; i<n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<'\n';
    int ans = 0;
    for(int i = 0; i<n; i++)
    {
        if(arr[i] == 0)
        {
            ans = i + 1;
            break;
        }
    }
    cout<<ans<<'\n';

}
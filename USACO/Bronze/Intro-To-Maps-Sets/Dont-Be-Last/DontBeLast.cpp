#include<bits/stdc++.h>
using namespace std;
int main()
{
    string name = "notlast";
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    int n;
    cin>>n;
    map<string, int>m;
    for(int i = 0 ; i < n; i++ )
    {
        string s; int k;
        cin>>s>>k;
        m[s] += k;
    }
    // bool  tie = false;
    string last = "";
    string secondLast = "";
    pair<int, string> arr[m.size()];
    if(m.size() == 1)
    {
        for(auto x: m)
        {
            cout<<x.first<<'\n';
        }
        return 0;
    }
    int i = 0;
    map<int, vector<string>>mp;
    for(auto x: m)
    {
        mp[x.second].push_back(x.first);
    }
    if(mp.size() == 1)
    {
        cout<<"Tie\n";
    }
    else
    {
        int i =0;
        for(auto j: mp)
        {
            i++;
            if(i == 2 && j.second.size()>1)
            {
                cout<<"Tie\n";
            }
            else if(i == 2)
            {
                cout<<j.second[0]<<'\n';
            }
        }
    }
    return 0;
}
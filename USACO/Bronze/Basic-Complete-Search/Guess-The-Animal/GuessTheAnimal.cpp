//Guess the animal
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
void setIO(string name = "")
{
    if(name.size() == 0)
        return;
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
int main()
{
    setIO("guess");
    int n;
    cin>>n;
    string keys[n];
    map<string , set<string>>m;
    for(int i = 0; i<n; i++)
    {
        cin>>keys[i];
        int count;
        cin>>count;
        for(int j = 0 ; j<count; j++)
        {
            string characteristic;
            cin>>characteristic;
            m[keys[i]].insert(characteristic);
        }
    }
    int mx  = 0;
    for(int i = 0; i<n; i++)
    {
        for(int j = i + 1; j< n; j++)
        {
            int cnt = 0;
            for(auto x: m[keys[i]])
            {
                cnt += (m[keys[j]].find(x)!=m[keys[j]].end());
            }
            mx = max(mx, cnt);
        }
    }
    cout<<mx + 1<<'\n';
    
}
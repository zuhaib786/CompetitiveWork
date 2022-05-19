#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
using vc = vector<lli>;
#define ff first
#define ss second
#define FOR(i, n) for(int i = 0; i<n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0; i--)
const int maxN  = 1e5 + 5;
vc arr[maxN];
void setIO(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
void printMap(map<lli, lli>m)
{
    cout<<"{";
    for(auto x: m)
    {
        cout<<x.first<<" : "<<x.second<<",";
    }
    cout<<"}\n";
}

int main()

{
    setIO("measurement");
    lli n, g;
    cin>>n>>g;
    // cin>>n;
    map<lli, lli>mp;
    set<lli>s;
    FOR(i,n)
    {
        int a, b,c;
        cin>>a>>b>>c;
        s.insert(b);
        mp[b] = g;
        arr[i].push_back(a);
        arr[i].push_back(c);
        arr[i].push_back(b);
    }
    
    sort(arr, arr + n);
    map<lli, lli>m;
    m[g] = s.size() + 1; 
    s = set<lli>();
    assert(s.size() == 0);
    s.insert(g);
    lli cnt = 0;
    FOR(i, n)
    {
        // printMap(m);
        lli a = arr[i][0], b = arr[i][2], c = arr[i][1];
        lli curMax = *s.rbegin();
        lli curCustMax = m[curMax];
        lli curValCow = mp[b];
        m[curValCow]-=1;
        if(m[curValCow] == 0)
        {
            m.erase(curValCow);
            s.erase(curValCow);
        }
        mp[b] = curValCow + c;
        m[mp[b]]++;
        s.insert(curValCow + c);
        // printMap(m);
        if(curMax == *s.rbegin() && m[curMax] == curCustMax)
        {
            continue;
        }
        if(curValCow + c == *s.rbegin() && curCustMax == 1 && curMax == curValCow && m[curValCow + c] == 1)
        {
            continue;
        }
        else
        {
            cnt++;
        }
    
    }
    cout<<cnt<<'\n';

}
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
map<lli, vector<pii>>m;
void setIO(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
void printSet(multiset<lli> & s)
{
    cout<<"Printing set\n";
    for(auto x: s)
    {
        cout<<x<<" ";
    }
    cout<<'\n';
}
const int maxN = 5e4 + 4;
pii cows[maxN];
int n;
lli solve(multiset<lli>& sx, multiset<lli> &sy)
{
    // Always separate on the basis of x. Then i will change orientation (x, y)-> (y, x) to get separation by y.
    // my map will be filled till now
    // cout<<"Kya dikkat hai bhai\n";
    lli ans = (*sx.rbegin() - *sx.begin())*(*sy.rbegin() - *sy.begin());
    set<lli>lx, ly;
    for(auto x: m)
    {
        // cout<<x.first<<'\n';
        // printSet(sx);
        // printSet(sy);
        for(auto p: x.second)
        {
            // cout<<p.first<<" "<<p.second<<'\n';
            lx.insert(p.first);
            ly.insert(p.second);
            sx.erase(sx.find(p.first));
            sy.erase(sy.find(p.second));
        }
        // printSet(sx);
        // printSet(sy);
        if(sx.size()!=0 && sy.size()!=0)
        {
            // cout<<*sx.begin()<<" "<<*sx.rbegin()<<" "<<*sy.begin()<<" "<<*sy.rbegin()<<'\n';
            // cout<<*lx.begin()<<" "<<*lx.rbegin()<<" "<<*ly.begin()<<" "<<*ly.rbegin()<<'\n';
            // cout<<"---------------\n";
            ans = min(ans, (*sx.rbegin() - *sx.begin())*(*sy.rbegin() - *sy.begin()) + (*lx.rbegin() - *lx.begin())*(*ly.rbegin() - *ly.begin()));
        }
        else
        {
            // cout<<*lx.begin()<<" "<<*lx.rbegin()<<" "<<*ly.begin()<<" "<<*ly.rbegin()<<'\n';
            // cout<<"---------------\n";
            ans = min(ans, (*lx.rbegin() - *lx.begin())*(*ly.rbegin() - *ly.begin()));
        }
    }
    return ans;
}
int main()
{
    setIO("split");
    multiset<lli>s;
    
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        cin>>cows[i].first>>cows[i].second;
    }
    multiset<lli>sx, sy;
    for(int i = 0; i<n; i++)
    {
        sx.insert(cows[i].first);
        sy.insert(cows[i].second);
        m[cows[i].first].push_back(cows[i]);
    }
    
    lli mx = (*sx.rbegin() - *sx.begin())*(*sy.rbegin() - *sy.begin());
    lli ans = solve(sx, sy);
    m.clear();
    sx = multiset<lli>();
    sy = multiset<lli>();
    for(int i = 0; i<n; i++)
    {
        sx.insert(cows[i].second);
        sy.insert(cows[i].first);
        m[cows[i].second].push_back({cows[i].second, cows[i].first});
    }
    ans = min(ans, solve(sx, sy));
    cout<<mx - ans<<'\n';
       
}

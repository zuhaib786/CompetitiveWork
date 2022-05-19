#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
#define ff first
#define ss second
#define FOR(i, n) for(int i = 0; i<n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0 ; i--)
const int maxN = 2e5 + 5;
multiset<lli>lengths;
set<lli>dif;
string s;
int n ;
void printSet(multiset<lli>s)
{
    cout<<"Printing set\n";
    for(auto x: s)
    {
        cout<<x<<" ";
    }
    cout<<'\n';
}
void solve(int x)
{
    if(x == 0 || x == n)
    return;
    if(dif.find(x)!=dif.end())
    {
        // cout<<"HERE\n";
        
        auto it = dif.find(x);
        lli a = *(next(it));
        lli b = *(prev(it));
        // cout<<x<<" "<<b<<" "<<'\n';
        assert(lengths.find( x- b)!= lengths.end());
        lengths.erase( lengths.find( x- b));
        assert(lengths.find( a- x)!= lengths.end());
        lengths.erase((lengths.find( a - x)));
        lengths.insert(a - b);
        dif.erase(it);
    }
    else

    {
        // cout<<"THERe\n";
        auto it = dif.insert(x).first;
        int a = *(next(it));
        int b = *(prev(it));

        lengths.erase(lengths.find(a - b));
        lengths.insert(a - x);
        lengths.insert(x - b);
    }
    // printSet(lengths);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>s;
    int m;
    cin>>m;
    n = s.size();
    
    dif.insert(0);
    dif.insert(n);
    
    int j = 0;
    FOR(i, n - 1)
    {
        if(s[i]!=s[i + 1])
        {
            dif.insert(i + 1);
        }
    }
    for(auto it = dif.begin(); next(it)!=dif.end(); it ++ )
    {
        lengths.insert(*next(it) - *it);
    }
    // printSet(lengths);
    FOR(i, m)
    {
        int a;
        cin>>a;
        solve(a - 1);
        solve( a);
        cout<<*lengths.rbegin()<<" ";
    }
    cout<<'\n';

}
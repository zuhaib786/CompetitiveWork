#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
void setIO(string name)
{
    cin.tie(0)->sync_with_stdio(0);
    freopen((name + ".in").c_str(), "r",stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
pair<string, string>rev(pair<string, string>p)
{
    return {p.second, p.first};
}
int main()
{
    setIO("citystate");
    int n;
    cin>>n;
    map<pair<string, string>, lli>m;
    for(int i = 0; i<n; i++)
    {
        string city, code;
        cin>>city>>code;
        string arr[2];
        arr[0] = city.substr(0,2);
        arr[1] = code;
        // sort(arr, arr + 2);
        m[{arr[0], arr[1]}]++;
    }
    lli ans = 0;
    for(auto y: m)
    {
        // if(y.second*m[rev(y.first)])
        //     cout<<y.second<<" "<<m[rev(y.first)]<<" "<<y.first.first<<" "<<y.first.second<<'\n';
        // come from different states
        if(rev(y.first) == y.first)
        {
            ans += 0;
        }
        else
        ans += y.second*m[rev(y.first)];
    }
    assert(ans %2 == 0);
    cout<<ans/2<<'\n';
}
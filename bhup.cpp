#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
ll mod = 1e9+7;

ll lcm(ll a, ll b)
{
    return (a*b)/(__gcd(a,b));
}

int gcd(int &x, int &y, int a, int b)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1,y1;
    int d = gcd(x1,y1,b,a%b);
    x = y1;
    y = x1-(a/b)*y1;
    return d;
}

ll binpow(ll a, ll n)
{
    if(n == 0) return 1;
    ll res = 1;
    while(n)
    {
        if(n & 1) res = (res*a)%mod;
        a = (a*a)%mod;
        n >>= 1;
    }
    return res;
}

int process(int res, int s, int e, vector<pair<int,int>> v)
{
        int curr = v[s].first;
        int ans = 0;
        int cans = v[s].second-1;
        for(int i = s+1; i < e; i++)
        {
            if(curr == res)
            {
                curr = v[i].first;
                ans += cans;
                cans = v[0].second-1;
            }
            else
            {
                curr &= v[i].first;
                cans += v[i].second;
            }
        }
        ans += cans;
        if(curr != res) ans++;
        return ans;
}
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a.begin(),a.end());
    vector<pair<int,int>> v;
    int cnt = 1;
    int res = a[0];
    unordered_set<int> us;
    for(int i = 1; i < n; i++)
    {
        us.insert(a[i]);
        res &= a[i];
        if(a[i] != a[i-1])
        {
            v.push_back({a[i-1],cnt});
            cnt = 1;
        }
        else
        {
            cnt++;
        }
    }
    v.push_back({a[n-1],cnt});
    if(us.find(res) != us.end())
    {
        for(int i = 0; i < v.size(); i++)
        {
            if(v[i].first == res)
            {
                int ans = 0;
                if(i-1 >= 0) ans += process(res,0,i,v);
                if(i+1 < v.size()) ans += process(res,i+1,v.size(),v);
                cout<<ans<<endl;
                return;
            }
        }
    }
    else
    {
        cout<<process(res,0,v.size(),v)<<endl;
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1; 
    cin>>t;
    while(t--)
    {
        solve();
    }
}
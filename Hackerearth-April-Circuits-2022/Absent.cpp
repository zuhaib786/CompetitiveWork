    #include<bits/stdc++.h>
    using namespace std;
    using lli = long long int;
    const lli mod = 1e9 + 7;
    const int maxN = 1e5 + 5;
    pair<lli, lli> dp[maxN];
    /* https://www.hackerearth.com/challenges/competitive/april-circuits-22/algorithm/absent-779cb434/ */
    void precalc()
    {
        dp[0] = {0, 0};
        dp[1] = {1, 1};
        dp[2] = {2, 1};
        for(int i = 2; i< maxN; i++)
        {
            dp[i].first = dp[i - 1].first + dp[i-1].second;
            dp[i].second =  dp[i-1].first;
            dp[i].first %= mod;
            dp[i].second %-mod;
        }
    }
    lli powMod(lli n, lli y)
    {
        lli accum = 1;
        while(y>0)
        {
            if(y&1)
            {
                accum*=n;
                accum %= mod;
            }
            n*=n;
            n%=mod;
            y = y/2;
        }
        return accum;
    }
    lli invMod(lli n)
    {
        return powMod(n, mod - 2);
    }
     
    int main() {
     
        ios::sync_with_stdio(0);
        cin.tie(0);
        int t;
        cin>>t;
        precalc();
        while(t--)
        {
            int n;
            cin>>n;
            lli ways;
            ways =  dp[n].second;
            // cout<<ways<<endl;
            ways %= mod;
            lli x = powMod(2, n - 1);
            ways = x - ways;
            ways %= mod;
            ways += mod;
            ways %= mod;
            ways *= invMod(x);
            ways %= mod;
            cout<<ways<<'\n';
        }
    }
    #include<bits/stdc++.h>
    using namespace std;
    using lli = long long int;
    const lli mod = 1e9 + 7;
    lli dp[500005];
    int main()
    {
        /* 
        https://www.hackerearth.com/challenges/competitive/april-circuits-22/algorithm/strange-sort-37e2d781/
        */
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int q, k;
        cin>>q>>k;
        dp[0] = 1;
        dp[1] = 1 + 1/k;
        for(int i = 2; i<500005; i++)
        {
            if(i - k>=0)
            {
                dp[i] += dp[i-k];
            }
            dp[i] += dp[i-1];
            dp[i]%=mod;
        }
        dp[0] = 0;
        for(int i = 1; i< 500005; i++)
        {
            dp[i] += dp[i-1];
            dp[i] %= mod;
        }
        while(q--)
        {
            int l , r;
            cin>>l>>r;
            l--;
            lli ans = 0;
            ans += dp[r];
            ans -= dp[l];
            ans %= mod;
            ans += mod;
            ans %= mod;
            cout<<ans<<'\n';
        }
        return 0;
    }
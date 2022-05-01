    #include<bits/stdc++.h>
    using namespace std;
    using lli = long long int;
    lli cost[100005];
    lli amnt[100005];
    lli d;
    pair<bool, lli> check(lli mid, lli n, lli m)
    {
        lli used = 0;
        for(int i = 0; i< mid; i++)
        {
            used += max(0ll, cost[mid - i- 1] -amnt[i]);
        }
        return {used <= d, used};
    }
    int main()
    {
        /* 
        https://www.hackerearth.com/challenges/competitive/april-circuits-22/algorithm/pirates-and-swords-89e51e63/
        */
        lli n, m;
        cin>>n>>m>>d;
        for(int i = 0; i< n; i++)
        {
            cin>>amnt[i];
        }
        for(int i = 0; i < m; i++)
        {
            cin>>cost[i];
        }
        
        sort(cost, cost + m);
        sort(amnt, amnt + n, greater<lli>());
        // can last k customers pucrchase first k items;
        lli left = 0;
        lli right = min(n, m) ;
        lli ans = 0;
        lli usedFinal = 0;
        while(left <= right)
        {
            lli mid = (right + left)/2;
            pair<bool, lli> bb = check(mid, n, m);
            bool b = bb.first;
            lli used = bb.second;
            if(b)
            {
                left = mid + 1;
                ans = mid;
                usedFinal = used;
            }
            else
            {
                right = mid - 1;
            }
        }
        lli totCost = 0;
        for(int i = 0; i< ans; i++)
        {
            totCost += cost[i];
        }
        // cout<<totCost<<endl;
        totCost -=  d;
        cout<<ans<<" "<<max(0ll, totCost)<<'\n';
        return 0;
    }
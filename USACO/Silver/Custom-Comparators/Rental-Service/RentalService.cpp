#include<bits/stdc++.h>
using namespace std;
using lli =long long int;
using pii = pair<lli , lli>;
void setIO(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
const int maxN = 1e5 + 5;
lli milk[maxN];
pii buyer[maxN];
lli rent[maxN];
lli money[maxN];
int main()
{
    setIO("rental");
    lli n, m,r;
    cin>>n>>m>>r;
    lli totMilk = 0;
    for(int i = 0; i< n; i++)
    {
        cin>>milk[i];
        // totMilk += milk[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin>>buyer[i].second>>buyer[i].first;
    }
    for(int i = 0; i<r; i++)
    {
        cin>>rent[i];
    }
    sort(milk , milk + n, greater<lli>());
    sort(buyer, buyer + m, greater<pii>());
    sort(rent, rent + r, greater<lli>());
    memset(money, 0, sizeof(money));
    int j = 0;
    
    for(int i = 0; i<n; i++)
    {
        
        if(i == 0)
        {
            
            while(j < m && milk[i] > 0)
            {
                if(milk[i] > buyer[j].second)
                {
                    money[i + 1] += (buyer[j]).first * buyer[j].second;
                    milk[i] -= buyer[j].second;
                    buyer[j].second = 0;
                    j++;
                }
                else
                {
                    money[i + 1] += milk[i] * buyer[j].first;
                    buyer[j].second -= milk[i];
                    milk[i] = 0;
                }
            }
        }
        else
        {
            money[i + 1] = money[i];
            while(j < m && milk[i] > 0)
            {
                if(milk[i] > buyer[j].second)
                {
                    money[i + 1] += buyer[j].first * buyer[j].second;
                    milk[i] -= buyer[j].second;
                    buyer[j].second = 0;
                    j++;
                }
                else
                {
                    money[i + 1] += milk[i] * buyer[j].first;
                    buyer[j].second -= milk[i];
                    milk[i] = 0;
                }
            }
        }
        // cout<<money[i + 1]<<" "<<j<<'\n';
    }
    // for(int i = 0; i<n + 1; i++)
    // {
    //     cout<<money[i]<<" ";
    // }
    // cout<<'\n';
    lli ans = money[n];
    lli curRent = 0;
    for(int i = 0; i < min(r, n); i++)
    {
        curRent += rent[i];
        ans = max(ans, money[n - 1- i] + curRent);
    }
    cout<<ans<<'\n';

}
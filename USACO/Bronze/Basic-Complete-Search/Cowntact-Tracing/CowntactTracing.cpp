#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
const int maxN = 101;
const int maxT = 251;
int n,t;
string endstate;
int finale[maxN];
pii shakes[maxT];
int cnt[maxN];
int infect[maxN];
void setIO(string name = "")
{
    if(name.size())
    {
        cin.tie(0)->sync_with_stdio(0);
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
bool check(int pointzero, int k)
{
    memset(cnt, 0, sizeof(cnt));
    memset(infect, 0, sizeof(infect));
    infect[pointzero] = 1;
    for(int tt = 1; tt < maxT; tt++)
    {
        if(shakes[tt].first >0)
        {
            int x = shakes[tt].first, y = shakes[tt].second;
            // cout<<tt<<" "<<x<<" "<<y<<'\n';
            if(infect[x])
            {
                cnt[x]++;
            }
            if(infect[y])
            {
                cnt[y]++;
            }
            if(cnt[x] <= k && infect[x])
            {
                infect[y] = 1;
            }
            if(cnt[y] <= k && infect[y])
            {
                infect[x] = 1;
            }
        }
    }
    for(int i = 1; i<= endstate.size(); i++)
    {
        if(infect[i] != finale[i])
            return false;
    }
    return true;

}
int main()
{
    setIO("tracing");
    cin>>n>>t;
    cin>>endstate;
    // cout<<endstate<<'\n';
    for(int i = 0; i<endstate.size(); i++)
    {
        finale[i + 1] = endstate[i] == '1';
    }
    // memset(shakes, {0,0},sizeof(shakes));
    for(int i = 0; i<maxT; i++)
    {
        shakes[i] = {0,0};
    }
    for(int i = 0; i<t; i++)
    {
        int time, x,y;
        cin>> time >> x >> y;
        shakes[time] = {x,y};
    }
    int ul = INT_MIN;
    int lol = INT_MAX;
    set<int>pzs;
    for(int i = 1; i <= n; i++)
    {
        for(int k = 0  ; k <= 251; k++)
        {
            if(check(i, k))
            {
                // cout<<"HElLO\n";
                pzs.insert(i);
                ul = max(ul, k);
                lol = min(lol, k);
            }
        }
    }
    cout<<pzs.size()<<" "<<lol<<" ";
    if(ul == maxT)
    {
        cout<<"Infinity\n";
    }
    else{
        cout<<ul<<'\n';
    }


}
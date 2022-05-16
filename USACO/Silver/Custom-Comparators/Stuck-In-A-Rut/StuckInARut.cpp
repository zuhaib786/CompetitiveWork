#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli , lli>;

#define all(x) x.begin(),  x.end()
struct cow
{
    lli x, y, i;
};
struct event
{
    lli i1, i2 , time, winner;
};
bool comp( event & e1 ,  event &e2)
{
    return e1.time < e2.time;
}
const int maxN = 1e3 + 3;
int stopper[maxN];
lli stoppingTime[maxN];
cow cows[maxN];
lli blame[maxN];
map<lli, vector<lli>>m;
void solve(int i)
{
    if(blame[i]!=0)
    {
        return ;
    }
    blame[i] = 1;
    for(auto x: m[i])
    {
        solve(x);
        blame[i] += blame[x];
    }
    return;
}
int main()
{
    // only two directions....XD
    // No two cows have same x coordinates
    // No two cows have same y coordinates
    // This is helpful. I overlooked it in my previous solution. The solution could have been simpler.
    vector<cow>east;
    vector<cow>north;
    vector<event>events;
    int n;
    cin>>n;
    for(int i = 0; i< n; i++)
    {
        char dir ;
        cin>>dir;
        if(dir == 'E')
        {
            cin>>cows[i].x>>cows[i].y;
            cows[i].i = i;
            east.push_back(cows[i]);
        }
        else
        {
            cin>>cows[i].x>>cows[i].y;
            cows[i].i = i;
            north.push_back(cows[i]);
        }
    }
    for(auto c1 : east)
    {
        for(auto c2 : north)
        {
            lli xdis = c2.x - c1.x;
            lli ydis = c1.y - c2.y;
            if(xdis > ydis && ydis > 0)
            {
                events.push_back({c1.i, c2.i, xdis, c2.i});
            }
            if(ydis > xdis && xdis > 0)
            {
                events.push_back({c1.i, c2.i, ydis, c1.i});
            }
        }
    }
    sort(all(events), comp);
    memset(stopper, -1, sizeof(stopper));
    for(int i = 0; i<maxN; i++)
    {
        stoppingTime[i] = LONG_MAX;
    }
    // for(auto e: events)
    // {
    //     cout<<e.i1 + 1<< " "<<e.i2 + 1<< " "<<e.winner + 1<<" "<<e.time<<" \n";
    // }
    for(auto e: events)
    {
        lli i1 = e.i1, i2 = e.i2, time = e.time, winner = e.winner;
        lli loser = winner == i1? i2: i1;
        if(stopper[loser] != -1)
        {
            continue;
        }
        if(stopper[winner] == -1)
        {
            stopper[loser] = winner;
            stoppingTime[loser] = time;
        }
        else
        {
            // winner has been stopped at some time. If this time is more than when it crosses common point of intersectio, then it become stopper of current one too.
            cow c1 = cows[i1];
            cow c2 = cows[i2];
            
            lli pass;
            if(winner == i1)
            {
                // east cow wins. 
                pass = c2.x - c1.x;
            }
            else
            {
                pass = c1.y - c2.y;
            }
            // cout<<i1<<" "<<i2<<" "<<pass<<" "<<winner<<" "<<loser<<'\n';
            if(pass < stoppingTime[winner])
            {
                stopper[loser] = winner;
                stoppingTime[loser] = time;
            }
        }
        // loser has not been stopped yet;
    }
    for(int i = 0; i<n; i++)
    {
        // cout<<stopper[i]<<" ";
        if(stopper[i] == -1)
        {
            continue;
        }
        else
        {
            m[stopper[i]].push_back(i);
        }
    }
    // cout<<'\n';
    // for(int i = 0; i<n; i++)
    // {
    //     cout<<stoppingTime[i]<<" ";
    // }
    // cout<<'\n';
    memset(blame, 0, sizeof(blame));
    for(int i = 0; i<n; i++)
    {
        if(blame[i] == 0)
        {
            solve(i);
        }
    }
    for(int i = 0; i< n; i++)
    {
        cout<<blame[i] - 1<<"\n";
    }
    return 0;
}

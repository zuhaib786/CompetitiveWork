#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli , lli>;
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
int main()
{
    // only two directions....XD
    int n;
    cin>>n;
    cow cows[n];
    vector<cow>eastCows;
    vector<cow>northCows;
    for(int i = 0; i<n; i++)
    {
        string dir; lli x, y;
        cin>>dir>>x>>y;
        if(dir == "E")
        {
            eastCows.push_back({x,y, i + 1});
        }
        else
        {
            northCows.push_back({x,y, i + 1});
        }
        cows[i] = {x, y, i+ 1};
    }
    vector<event>v;
    set<int>lostCows;
    for(auto c1: eastCows)
    {
        for(auto c2:northCows)
        {
            if(c1. x > c2.x || c1.y < c2.y )
                continue;
            lli t1 = c2.x - c1.x;
            lli t2 = c1.y - c2.y;
            if(t1 == t2)
                continue;
            if(t1 < t2)
            {
                // c1 is winner
                v.push_back({c1.i, c2.i, t1, c1.i});
            }
            else
            {
                v.push_back({c1.i, c2.i, t2, c2.i});
            }
        }
    }
    for(auto c1: eastCows)
    {
        for(auto c2:eastCows)
        {
            if(c1.i == c2.i)
                continue;
            if(c1.y !=c2.y)
                continue;
            if(c1.x > c2.x)  
            {
                int t = c1.x - c2.x;
                v.push_back({c1.i, c2.i, t, - c2.i});
            } 
            else
            {
                int t = c2.x - c1.x;
                v.push_back({c1.i,c2.i ,t, -c1.i});
            }
        }
    }
    for(auto c1: northCows)
    {
        for(auto c2:northCows)
        {
            if(c1.i == c2.i)
                continue;
            if(c1.x !=c2.x)
                continue;
            if(c1.y > c2.y)  
            {
                int t = c1.y - c2.y;
                v.push_back({c1.i, c2.i, t, - c2.i});
            } 
            else
            {
                int t = c2.y - c1.y;
                v.push_back({c1.i,c2.i,  t, -c1.i});
            }
        }
    }
    sort(v.begin(), v.end(), comp);
    // for(auto x : v)
    // {
    //     cout<<x.time<<" "<<x.i1<<" "<<x.i2<<" "<<x.winner<<'\n';
    // }
    vector<lli> ans(n, INT_MAX);
   
    lli time = 0;
    set<pii>s;
    for(int i = 0; i<v.size(); i++)
    {
        event e = v[i];
        time = e.time;
        while(s.size()!=0 && (*s.begin()).first <= time)
        {
            lostCows.insert((*s.begin()).second);
            s.erase(*s.begin());
        }
        if(e.winner < 0)
        {
            int i1 = e.i1;
            int i2 = e.i2;
            int w =  -e.winner;
            if(i1 == w)
            {
                ans[i2  - 1] = min(ans[i2 - 1], time);
                lostCows.insert(i2);

            }
            else 
            {
                ans[i1 - 1] = min(ans[i1 - 1], time);
                lostCows.insert(i1);
            }
        }
        else
        {
            int i1 = e.i1;
            int i2 = e.i2;
            int winner = e.winner;
            if(lostCows.find(winner) != lostCows.end())
            {
                continue;
            }
            else
            {
                if(i1 == winner)
                {
                    ans[i2 - 1] = min(ans[i2 - 1],  cows[i1 - 1].y - cows[i2 - 1].y);
                    s.insert({cows[i1 - 1].y - cows[i2 - 1].y, i2});
                }
                else
                {
                    ans[i1 - 1] = min(ans[i1 - 1], cows[i2 - 1].x - cows[i1 - 1].x);
                    s.insert({cows[i2 - 1].x - cows[i1 - 1].x, i1});
                }
            }
        }
        
    }
    for(int i = 0; i<n; i++)
    {
        if(ans[i] == INT_MAX)
        {
            cout<<"Infinity\n";
        }
        else
        {
            cout<<ans[i]<<'\n';
        }
    }
}

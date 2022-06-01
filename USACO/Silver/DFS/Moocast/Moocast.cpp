#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
using vc = vector<lli>;

#define ff first
#define ss second
#define FOR(i, n) for(int i = 0; i<n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0; i--)

const int maxN = 201;
vector<int>adj[maxN];
struct cow
{
    int x, y, power;
};
cow cows[maxN];
int solve(int i)
{
    stack<int>s;
    s.push(i);
    vector<int>visited(maxN, 0);
    while (!s.empty())
    {
        int x = s.top();
        s.pop();
        visited[x] = 1;
        for(auto y: adj[x])
        {
            if(visited[y])
            continue;
            s.push(y);
        }
        /* code */
    }
    int sm = 0;
    for(auto x: visited)
    {
        sm += x;
    }
    return sm;
    
}
int main()
{
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int n;
    cin>>n;
    FOR(i, n)
    {
        cin>>cows[i].x>>cows[i].y>>cows[i].power;
    }
    for(int i = 0; i< n; i++)
    {
        for(int j = i + 1; j<n; j++)
        {
            lli dis = (cows[i].x - cows[j].x)*(cows[i].x - cows[j].x) + (cows[i].y - cows[j].y)*(cows[i].y - cows[j].y);
            if(dis <= cows[i].power * cows[i].power)
            {
                adj[i].push_back(j);
            }
            if(dis <= cows[j].power * cows[j].power)
            {
                adj[j].push_back(i);
            }
        }
    }
    int ans = 0;
    for(int i =0; i<n; i++)
    {
        ans = max(ans, solve(i));
    }
    cout<<ans<<'\n';
}
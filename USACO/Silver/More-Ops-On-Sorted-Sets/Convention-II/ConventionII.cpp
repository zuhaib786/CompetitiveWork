#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli,lli>;
using vc = vector<lli>;


#define ff first
#define ss second
#define FOR(i, n) for(int i = 0; i<n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0 ; i--)

const int maxN = 1e5 + 5;

struct event
{
    int startTime;
    int runTime;
    int identifier;
};

bool comp(const event &e1, const event & e2)
{
    if(e1.startTime == e2.startTime)
    {
        return e1.identifier < e2.identifier;
    }
    return e1.startTime < e2.startTime;
}
struct compare
{
    bool operator()(const event &e1, const event &e2)
    {
        return e1.identifier < e2.identifier;
    }
};
void setIO(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
event arr[maxN]; 
int main()
{
    setIO("convention2");
    multiset<event, compare>s;
    // set<int>s;
    int n;
    cin>>n;
    FOR(i,n)
    {
        cin>>arr[i].startTime>>arr[i].runTime;
        arr[i].identifier = i;
    }
    sort(arr, arr + n, comp);
    // s.insert(arr[0]);
    int j = 0;
    lli maxWaitTime = 0;
    lli curTime = 0;
    while(j < n || s.size()!=0)
    {
        while(j < n && arr[j].startTime < curTime )
        {
            s.insert(arr[j]);
            j++;
        }
        if(s.size() == 0)
        {
            curTime = arr[j].startTime;
            s.insert(arr[j]);
            j++;
        }
        auto it = *s.begin();
        // cout<<curTime<<" "<<it.identifier<<'\n';
        s.erase(s.find(it));
        maxWaitTime = max(maxWaitTime, curTime - it.startTime);
        curTime = curTime + it.runTime;
    }
    cout<<maxWaitTime<<'\n';

}

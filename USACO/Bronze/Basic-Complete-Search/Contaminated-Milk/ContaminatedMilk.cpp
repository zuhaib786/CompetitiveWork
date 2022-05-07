#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
void setIO(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
struct event
{
    int person, type, time;
};
bool comp(const event & e1, const event &e2)
{
    return make_pair(e1.time, make_pair(e1.person, e1.type)) < make_pair(e2.time, make_pair(e2.person, e2.type));
}
struct sick
{
    int person, time;
};
void intersection(set<int> & cur, set<int> & types)
{
    set<int>ans ;
    for(auto x: cur)
    {
        if(types.find(x)!=types.end())
        {
            ans.insert(x);
        }
    }
    cur = ans;
    return;
}
void printSet(set<int> & cur)
{
    cout<<"Printing set \n";
    for(auto x: cur)
    {
        cout<<x<<' ';
    }
    cout<<'\n';
}
int main()
{
    setIO("badmilk");
    int n,m,d,S;
    cin>>n>>m>>d>>S;
    event events[d];
    for(int i = 0; i<d; i++)
    {

        cin>>events[i].person>>events[i].type>>events[i].time;
        events[i].person--;
    }
    sort(events, events + d, comp);
    set<int> types[n];
    set<int>cur;
    for(int i = 1; i<=m; i++)
    {
        cur.insert(i);
    }
    int j = 0;
    pii sicks[S];
    for(int i = 0; i<S; i++)
    {
        cin>>sicks[i].second>>sicks[i].first;
    }
    sort(sicks, sicks + S);
    for(int i = 0; i<S; i++)
    {
        int person, time;
        person = sicks[i].second;
        time = sicks[i].first;   
        // cout<<"Person "<<person<<" time "<<time<<'\n';
        person--;
        while(j< d && events[j].time < time)
        {
            event k = events[j];
            // cout<<k.person<<" "<<k.time<<" "<<k.type<<'\n';
            types[k.person].insert(k.type);
            j++;

        }
        intersection(cur, types[person]);
    }
    set<int>ps;
    // printSet(cur);
    for(int i = 0; i<d; i++)
    {
        if(cur.find(events[i].type)!=cur.end())
            ps.insert(events[i].person);
    }
    // printSet(ps);
    cout<<ps.size()<<'\n';


}
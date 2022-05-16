#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<int, int>;
void setIO(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
struct worm
{
    int a, b, w;
};
bool comp(const worm & w1, const worm & w2)
{
    return w1.w  > w2.w;
}
class DSU
{
    public:
    vector<int>rank;
    vector<int>parent;
    DSU(int n)
    {
        rank = vector<int>(n, 0);
        parent  = vector<int>(n,0);
        for(int i = 0; i< n; i++)
        {
            parent[i] = i;
        }
    }
    int Find(int a)
    {
        while(parent[a]!= a)
        {
            a = parent[a];
        }
        return a;
    }
    void Union(int a , int b)
    {
        a = Find(a);
        b = Find(b);
        if(a==b)
        return;
        if(rank[a] >rank[b])
        {
            parent[b] = a;
        }
        else if (rank[a]<rank[b])
        {
            parent[a] = b;
        }
        else
        {
            parent[b] = a;
            rank[a]++;
        }
    }
    bool joined(int a, int b)
    {
        return  Find(a) == Find(b);
    }
    int maxCount()
    {
      //get maximum number of elements in a collection
        int ans = 0;
        map<int,int>m;
        for(int i = 0; i<parent.size(); i++)
        {
            m[parent[i]]++;
        }
        for(auto x: m)
        {
            ans = max(ans,x.second);
        }
        return ans;
    }
};
int main()
{
    setIO("wormsort");
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
        arr[i]--;
    }
    vector<worm>worms(m);
    for(int i = 0; i<m; i++)
    {
        cin>>worms[i].a>>worms[i].b>>worms[i].w;
        worms[i].a--;
        worms[i].b--;
    }
    DSU ds(n);
    lli mn = INT_MAX;
    sort(worms.begin(), worms.end(), comp);
    int idx = 0;
    for(int i = 0; i<n; i++)
    {
        while(!ds.joined(i, arr[i]))
        {
            // cout<<worms[idx].a<<" "<<worms[idx].b<<'\n';
            ds.Union(worms[idx].a, worms[idx].b);
            mn = worms[idx].w;
            idx++;
        }
    }
    if(mn != INT_MAX)
        cout<<mn<<'\n';
    else
        cout<<-1<<'\n';

}
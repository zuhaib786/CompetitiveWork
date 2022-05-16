#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
vector<string>v= {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
void setIO(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
string dfs(vector<int>adj[], int vert, bool visited[])
{
    string ans = "";
    ans += v[vert]+'\n';
    visited[vert] = true;
    for(auto x: adj[vert])
    {
        if(!visited[x])
        {
            visited[x] = 1;
            string temp = dfs(adj, x, visited);
            ans += temp;
        }
    }
    return ans;
}
int main()
{
    setIO("lineup");
    int n;
    cin>>n;
    vector<int>adj[v.size()];
    // vector<string>v= {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    sort(v.begin(), v.end());
    map<string, int>m;
    for(int i = 0; i<v.size(); i++)
    {
        m[v[i]] = i;
    }
    for(int i = 0; i<n; i++)
    {
        // Buttercup must be milked beside Bella
        string name1, must, be, milked, beside, name2;
        cin>>name1>>must>>be>>milked>>beside>>name2;
        assert(m.count(name1)!=0 && m.count(name2)!=0);
        adj[m[name1]].push_back(m[name2]);
        adj[m[name2]].push_back((m[name1]));
    }
    for(int i = 0; i<v.size(); i++)
    {
        assert(adj[i].size()<=2);
    }
    bool visited[v.size()];
    memset(visited, 0, sizeof(visited));
    string order = "";
    for(int i = 0; i<v.size(); i++)
    {
        // cout<<i<<" "<<adj[i].size()<<'\n';
        if(!visited[i] && adj[i].size() <= 1)
        {
            string s= dfs(adj, i, visited);
            order += s;
            // cout<<s;
        }
    }

    cout<<order;
}
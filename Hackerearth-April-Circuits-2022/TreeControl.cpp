#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using lli = long long int;
using pii = pair<int, int>;
const int maxN = 2e5 + 5;
typedef tree<pii, null_type, less<pii>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
set<int>s;
lli controls[maxN];
lli lengths[maxN];
int arr[maxN];
ordered_set dp[maxN];
int maxLevel =0;
/* https://www.hackerearth.com/challenges/competitive/april-circuits-22/algorithm/tree-control-48dc13f4/ */
void printSet(int u)
{
    cout<<"Printing set dp["<<u<<"]\n";
    for(auto x: dp[u])
    {
        cout<<x.first<<" ";
    }
    cout<<endl;
}
void printArr(int v[], int level)
{
    cout<<"Printing array \n";
    for(int i = 0; i<=level; i++)
    {
        cout<<"{"<<v[i]<<","<<lengths[v[i]]<<"} ";
    }
    cout<<'\n';
}
void printTemp(int temp [], int level)
{
    cout<<"printing temp\n";
    for(int i = 0; i< level + 1; i++)
    {
        cout<<temp[i]<<" ";
    }
    cout<<endl;
}
void printupdates(int simp[], int level)
{
    cout<<"Printing updates\n";
    for(int i = 0; i< level + 1; i++)
    {
        cout<<arr[simp[i]]<<" ";
    }
    cout<<endl;
}

void dfs(int vertex, int par, vector<pii>adj[], int v[], int simp[], int level)
{
    /* Created array for the dfs branch and then used simple opening and closing bracket idea to complete the task. Worked like a charm. Passed all test cases*/
    maxLevel = max(level, maxLevel);
    simp[level] = vertex;
    auto id = lower_bound(v, v + level + 1,  v[level] - controls[vertex]);
    int val = level  - (id - v) ;
    lengths[vertex] = val;
    for(auto x: adj[vertex])
    {
        if(x.first!= par)
        {
            v[level + 1] = v[level] + x.second;
            dfs(x.first, vertex, adj, v, simp, level + 1);
        }
    }
    if(adj[vertex].size() == 0)
    {
        int temparr[level + 1];
        memset(temparr,0, sizeof(temparr));
        for(int i = 0; i< level+ 1; i++)
        {
            if(s.find(simp[i])!= s.end())
            {
                continue;
            }
            s.insert(simp[i]);
            int id = lengths[simp[i]];
            assert(id>=0);
            if(id!=0)
            {
                temparr[i -  1] += 1;
                if(i - id - 1>=0)
                {
                    temparr[i - id - 1] -=1;
                }
            }
        }
        int curVal = 0;
        for(int i = level; i>=0; i--)
        {
            curVal += temparr[i];
            arr[simp[i]] += curVal;
        }
    }
}


void auxDfs(int u, int par, vector<pii>adj[], int level)
{
    /* Using merging data structures. Algorithm failed to pass 1 test case: TLE */
    
    for(auto x: adj[u])
    {
        if(x.first != par)
        {
            auxDfs(x.first, u, adj, level+1);
            if(dp[u].size() < dp[x.first].size())
            {
                swap(dp[u], dp[x.first]);
            }
            for(auto y : dp[x.first])
            {
                dp[u].insert(y);
            }
        }
    }

    arr[u] = dp[u].size() - dp[u].order_of_key({maxLevel - level,   - 1});
    dp[u].insert({lengths[u] + maxLevel - level,u });
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<pii>adj[n];
    
    int v[n];
    int simp[n];
    for(int i = 0; i< n; i++)
    {
        cin>>controls[i];
    }
    
    for(int i = 0; i< n-1; i++)
    {
        cin>>arr[i];
    }
    
    for(int i = 0; i< n - 1; i++)
    {
        int pi = arr[i];
        pi--;
        int wt;
        cin>>wt;
        adj[pi].push_back({i + 1, wt});
    }
    v[0] = 0;
    memset(arr, 0, sizeof(arr));
    dfs(0, - 1, adj, v, simp,  0);

    for(int i = 0; i< n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<'\n';
}
#include<bits/stdc++.h>
using namespace std;
void dfs(int u, int par, vector<int>adj[], vector<int> & prev, vector<int>&fin, vector<int>&col)
{
	fin[u] = prev[col[u]];
    // cout<<u<<" "<<fin[u]<<endl;
	prev[col[u]] = u;

	for(auto x: adj[u])
	{
		if(x != par)
		{
			dfs(x, u, adj, prev, fin, col);
		}
	}
    prev[col[u]] = fin[u];
}
int main()
{
	int n,c;
	cin>>n>>c;
	vector<int>adj[n];
	vector<int>prev(c,  -1);
	vector<int>fin(n);
	for(int i = 1; i<n ; i++)
	{
		int k;
		cin>>k;
		k-- ;
		adj[i].push_back(k);
		adj[k].push_back(i);
	}
    
	vector<int>col(n);
	for(int i = 0; i< n; i++)
	{
		cin>>col[i];
		col[i]--;
	}
	dfs(0, -1, adj, prev, fin, col);
	for(int i = 0; i< n; i++)
	{
		if(fin[i] == -1)
            cout<<-1<<" ";
        else
            cout<<fin[i] + 1<<" ";
	}

	cout<<endl;
}
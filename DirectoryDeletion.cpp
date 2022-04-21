#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
set<int>delIds;
void dfs(int u, int par, vector<int>adj[])
{
    // cout<<u<<endl;
	if(delIds.find(u) != delIds.end())
	{
        // cout<<u<<endl;
		cnt++;
		return;
	}
	for(auto x: adj[u])
	{
		if(x != par)
		{
			dfs(x, u, adj);
		}
	}	
	return;
}
int main()
{
	int n;
	cin>>n;
	vector<int>adj[n];
	for(int i = 0; i< n ; i++)
	{
		int k;
		cin>>k;
		if( i == 0)
			continue;
		k--;
		adj[k].push_back(i);
		// adj[i].push_back(k);
	}
	
	int m;
	cin>>m;
	for(int i = 0; i< m; i++)
	{
		int k;
		cin>>k;
		k--;
		delIds.insert(k);
	}
	dfs(0, -1, adj);
	cout<<cnt<<endl;
}
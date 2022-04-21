#include<bits/stdc++.h>
using namespace std;
string s;
void dfs(int u, int par, vector<int>adj[], vector<vector<int>> &preComp)
{
	for(auto x: adj[u])
	{
		if(x!=par)
		{
			dfs(x, u, adj, preComp);
			for(int i = 0; i< 26; i++)
			{
				preComp[u][i] += preComp[x][i];
			}
		}
		
	}
	int idx = (int)s[u] - (int)'a';
	preComp[u][idx]++;
}
int main()
{
	int n, q;
	cin>>n>>q;
	cin>>s;
	vector<int>adj[n];
	vector<vector<int>>preComp(n, vector<int>(26, 0));
	for(int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin>>a>>b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0, -1,  adj, preComp);
	for(int i = 0; i<q; i++)
	{
		int u; char c;
		cin>>u>>c;
        u--;
		int idx = (int)c - (int) 'a';
		cout<<preComp[u][idx]<<'\n';
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace  std;

int main()
{
	int n;
	cin>>n;
	vector<int >adj[n];
	for(int i = 0; i<n-1; i++)
	{
		int a, b;
		cin>>a>>b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// for(int i = 0; i< n; i++)
	// {
	// 	for(auto x: adj[i])
	// 	{
	// 		cout<<x<<" ";
	// 	}
	// 	cout<<endl;
	// }
	vector<int>dis(n, INT_MAX);
	vector<int>visited(n, 0);
	queue<int>q;
	q.push(0);
	dis[0] = 0;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		if(visited[u])
			continue;
		// cout<<"HELLO\n";
		visited[u] = 1;
		for(auto v: adj[u])
		{
			if(!visited[v])
			{
				q.push(v);
				dis[v] = min(dis[v], dis[u] + 1);
			}
		}
	}
	int maxId = 0;
	for(int i = 0; i < n; i++)
	{
		if(dis[i] > dis[maxId])
			maxId = i;
	}
	// for(auto x: dis)
	// {
	// 	cout<<x<<" ";
	// }
	// cout<<endl;
	visited = vector<int>(n,0);
	q.push(maxId);
	dis = vector<int>(n, INT_MAX);
	dis[maxId] = 0;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		if(visited[u])
			continue;
		visited[u] = 1;
		for(auto v: adj[u])
		{
			if(!visited[v])
			{
				q.push(v);
				dis[v] = min(dis[v], dis[u] + 1);
			}
		}
	}
	// for(auto x: dis)
	// {
	// 	cout<<x<<" ";
	// }
	// cout<<endl;
	int maxId1 = 0;
	for(int i = 0; i < n; i++)
	{
		if(dis[i] > dis[maxId1])
			maxId1 = i;
	}
	cout<<maxId1 + 1<<" "<<maxId + 1<<endl;
}
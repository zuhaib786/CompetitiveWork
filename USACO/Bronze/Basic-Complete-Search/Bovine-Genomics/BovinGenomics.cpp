#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
void setIO(string name = "")
{
	if(name.size() == 0)
		return;
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}
int main()
{
	setIO("cownomics");
	int n,m;
	cin>>n>>m;
	string spotted[n];
	string plain[n];
	for(int i = 0; i<n; i++)
	{
		cin>>spotted[i];
	}
	for(int i = 0; i<n; i++)
	{
		cin>>plain[i];
	}
	int cnt = 0;
	for(int j = 0; j<m; j++)
	{
		set<char>ss;
		for(int i = 0; i<n; i++)
		{
			ss.insert(spotted[i][j]);
		}
		set<char>sp;
		for(int i =0 ; i <n; i++)
		{
			sp.insert(plain[i][j]);
		}
		bool b = true;
		for(auto x: ss)
		{
			if(sp.find(x)!=sp.end())
				b = false;
		}
		cnt += b;
	}
	cout<<cnt<<'\n';

}
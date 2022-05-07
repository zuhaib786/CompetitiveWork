#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
void setIO(string name ="")
{
	if(name.size() == 0)
		return ;
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}
int sgn(int x)
{
	if(x < 0)
		return -1;
	return 1;
}
int main()
{
	setIO("gymnastics");
	int k,n;
	cin>>k>>n;
	int arr[k][n];
	for(int i = 0; i<k; i++)
	{
		for(int j =0; j<n; j++)
		{
			int w;
			cin>>w;
			w--;
			arr[i][w] = j;
		}
	}
	int ans = 0;
	for(int i = 0; i<n; i++)
	{
		for(int j = i + 1; j<n; j++)
		{
			bool b = true;
			int s =sgn(arr[0][i] - arr[0][j]);
			for(int d = 0; d<k; d++)
			{
				b = b&&(s == sgn(arr[d][i] - arr[d][j]));
			}
			ans += b;
		}
	}
	cout<<ans<<'\n';
}


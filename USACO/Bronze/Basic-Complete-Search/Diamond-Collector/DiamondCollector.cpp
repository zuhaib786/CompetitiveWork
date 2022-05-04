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
	setIO("diamond");
	int n,k;
	cin>>n>>k;
	lli arr[n];
	for(int i = 0; i<n; i++)
	{
		cin>>arr[i];
	}
	sort(arr, arr + n);
	int cnt = 0;
	for(int i = 0; i<n; i++)
	{
		for(int j = i; j<n; j++)
		{
			if(arr[j] - arr[i] <= k)
			{
				cnt = max(cnt , j - i + 1);
			}
		}	
	}
	cout<<cnt<<'\n';
}

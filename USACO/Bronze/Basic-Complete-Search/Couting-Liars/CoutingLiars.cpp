#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<int, int>;
void setIO(string name = "")
{
	if(name.size() == 0)
		return;
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

int main()
{
	// setIO("liars");
	int n;
	cin>>n;
	pii arr[n];
	for(int i = 0; i<n; i++)
	{
		string s;
		cin>>s;
		if(s == "G")
		{
			cin>>arr[i].first;
			arr[i].second = 1;
		}
		else
		{
			cin>>arr[i].first;
			arr[i].second = -1;
		}
	}
	sort(arr, arr + n);
	lli mn = INT_MAX;
	for(int i = 0; i<n; i++)
	{
		lli agree = 0;
		for(int j= 0; j<n; j++)
		{
			if(arr[j].second == -1)
			{
				agree += (arr[i].first <= arr[j].first);
			}
			else
			{
				agree += (arr[i].first >= arr[j].first);
			}
		}
		mn = min(mn, n - agree);
	}
	cout<<mn<<'\n';
}

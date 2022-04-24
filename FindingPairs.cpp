#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
lli arr[1000006];
int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i = 0; i< n; i++)
		{
			cin>>arr[i];
		}
		sort(arr, arr + n);
		lli l = 0;
		lli cur = -1;
		lli ans = 0;
		for(int i = 0; i< n; i++)
		{
			if(arr[i] == cur)
			{
				l++;
			}
			else
			{
				cur = arr[i];
				ans += l + (l*(l - 1))/2;
				l = 1;
			}
		}
		ans += l + (l*(l - 1))/2;
		cout<<ans<<'\n';
	}
}
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pss = pair<string, string>;
int main()
{
	ifstream mycin;
	mycin.open("blocks.in");
	ofstream mycout;
	mycout.open("blocks.out");
	int n;
	mycin>>n;
	pss blocks[n];
	for(int i  = 0; i< n; i++)
	{
		mycin>>blocks[i].first>>blocks[i].second;
	}
	int ans [26];
	for(int j = 0; j <26; j++ )
	{
		int tot = 0;
		for(int i =0 ; i<n; i++)
		{
			int cnt = 0;
			for(int k = 0; k<blocks[i].first.size(); k++)
			{
				int z = blocks[i].first[k] - 'a';
				cnt += (z == j);
			}
			int cnt2 = 0;
			for(int k = 0; k<blocks[i].second.size(); k++)
			{
				int z = blocks[i].second[k] - 'a';
				cnt2 += (z == j);
			}
			tot += max(cnt, cnt2);
		}
		ans[j] = tot;
	}
	for(int i  = 0; i< 26; i++)
	{
		mycout<<ans[i]<<'\n';
	}

}

#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
int main()
{
	ifstream mycin;
	mycin.open("mowing.in");
	ofstream mycout;
	mycout.open("mowing.out");
	int n;
	mycin>>n;
	map<pii, int>m;
	pii pos = {0,0};
	lli x = INT_MAX;
	lli time = 0;
	for(int i =0; i<n; i++)
	{
		char dir; int length;
		mycin>>dir>>length;
		if( dir == 'N')
		{
			for(int t = 1; t<=length; t++)
			{
				pos.first++;
				time++;
				if(m.count(pos))
				{
					x = min(x, time - m[pos]);
				}
				m[pos] = time;
			}
		}
		else if(dir == 'S')
		{
			for(int t = 1; t<=length; t++)
			{
				pos.first--;
				time++;
				if(m.count(pos))
				{
					x = min(x, time - m[pos]);
				}
				m[pos] = time;
			}
		}
		else if (dir == 'E')
		{
			for(int t = 1; t<=length; t++)
			{
				pos.second++;
				time++;
				if(m.count(pos))
				{
					x = min(x, time - m[pos]);
				}
				m[pos] = time;
			}
		}
		else
		{
			for(int t = 1; t<=length; t++)
			{
				pos.second--;
				time++;
				if(m.count(pos))
				{
					x = min(x, time - m[pos]);
				}
				m[pos] = time;
			}
		}
	}
	if(x!=INT_MAX)
		mycout<<x<<'\n';
	else
		mycout<<-1<<'\n';

}
